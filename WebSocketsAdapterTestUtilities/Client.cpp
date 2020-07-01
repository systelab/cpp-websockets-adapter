#include "StdAfx.h"
#include "Client.h"

#pragma warning (push)
#pragma warning (disable:4512)
#include "ClientImpl.h"
#pragma warning (pop)

#include "IMessageHandler.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	Client::Client(const std::string& name,
				   const std::string& uri,
				   IMessageHandler& messageHandler)
		:m_name(name)
		,m_impl(ClientImpl::from_url(uri))
		,m_messageHandler(messageHandler)
		,m_thread()
	{
	}

	Client::~Client()
	{
	}

	void Client::connect()
	{
		m_thread.reset(new boost::thread(boost::bind(&Client::runThread, this)));
	}

	void Client::disconnect()
	{
		m_impl->close();
		m_thread->join();
		m_thread.reset();
	}

	void Client::sendMessage(const std::string& message)
	{
		m_impl->send(message);
	}

	void Client::runThread()
	{
		while (m_impl->getReadyState() != ClientImpl::CLOSED)
		{
			m_impl->poll();
			m_impl->dispatch(
				[this](const std::string& message)
				{
					std::cout << "[" << m_name << "] Message received: " << message << std::endl;
					m_messageHandler.handleMessage(message);
				}
			);
		}
	}

}}}
