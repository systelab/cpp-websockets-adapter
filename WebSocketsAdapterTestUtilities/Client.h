#ifndef _TESTUTILITIES_CLIENT_QUIM_VILA_3101181134_H
#define _TESTUTILITIES_CLIENT_QUIM_VILA_3101181134_H

#include <boost/thread.hpp>


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class IMessageHandler;
	class ClientImpl;

	class Client
	{
	public:
		Client(const std::string& name,
			   const std::string& uri,
			   IMessageHandler&);
		virtual ~Client();

		void connect();
		void disconnect();
		void sendMessage(const std::string& message);

	private:
		void runThread();

	private:
		std::string m_name;
		std::unique_ptr<ClientImpl> m_impl;
		IMessageHandler& m_messageHandler;
		boost::shared_ptr<boost::thread> m_thread;
	};

}}}

#endif //_TESTUTILITIES_CLIENT_QUIM_VILA_3101181134_H