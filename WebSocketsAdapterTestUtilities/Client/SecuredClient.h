#pragma once

#include <string>
#include <websocketpp/config/asio.hpp>
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>

#include <boost/thread.hpp>

namespace systelab {namespace websockets_adapter {	namespace test_utility {

	class IMessageHandler;

	class SecuredClient
	{
	public: 
		SecuredClient(const std::string& name, const std::string& uri, IMessageHandler&);
		int connect();
		void sendMessage(const std::string&);
		void disconnect();

	protected:
		std::string m_name;
		std::string m_uri;
		IMessageHandler & m_messageHandler;
		typedef websocketpp::client<websocketpp::config::asio_tls_client> client;
		client m_client;
		client::connection_ptr m_connection;
		boost::shared_ptr<boost::thread> m_thread;

		void onMessage(websocketpp::connection_hdl hdl, websocketpp::config::asio_client::message_type::ptr msg);
		bool onVerifyCertificate(const char * hostname, bool preverified, boost::asio::ssl::verify_context& ctx);
		typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> context_ptr;
		context_ptr onTLSInit(const char * hostname, websocketpp::connection_hdl connection);
		void runThread();
	};
}}}