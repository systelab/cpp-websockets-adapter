#include "stdafx.h"

#pragma warning(push)
#pragma warning(disable:4127)
#pragma warning(disable:4996)
#pragma warning(disable:4244)

#include "SecuredClient.h"
#include "WebSocketsAdapterTestUtilities/IMessageHandler.h"

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#pragma warning(pop)
#include <iostream>


namespace systelab {namespace websockets_adapter {	namespace test_utility {

	typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> context_ptr;

	using websocketpp::lib::placeholders::_1;
	using websocketpp::lib::placeholders::_2;
	using websocketpp::lib::bind;

	// pull out the type of messages sent by our config
	typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

	SecuredClient::SecuredClient(const std::string& name, const std::string& uri, IMessageHandler& handler)
		:m_name(name)
		, m_uri(uri)
		, m_messageHandler(handler)
		, m_thread()
		, m_connection()
	{
	}

	bool SecuredClient::onVerifyCertificate(const char * /*hostname*/, bool /*preverified*/, boost::asio::ssl::verify_context& /*ctx*/)
	{
		// The verify callback can be used to check whether the certificate that is
		// being presented is valid for the peer. For example, RFC 2818 describes
		// the steps involved in doing this for HTTPS. Consult the OpenSSL
		// documentation for more details. Note that the callback is called once
		// for each certificate in the certificate chain, starting from the root
		// certificate authority.

		// Retrieve the depth of the current cert in the chain. 0 indicates the
		// actual server cert, upon which we will perform extra validation
		// (specifically, ensuring that the hostname matches. For other certs we
		// will use the 'preverified' flag from Asio, which incorporates a number of
		// non-implementation specific OpenSSL checking, such as the formatting of
		// certs and the trusted status based on the CA certs we imported earlier.
		//int depth = X509_STORE_CTX_get_error_depth(ctx.native_handle());

		//// if we are on the final cert and everything else checks out, ensure that
		//// the hostname is present on the list of SANs or the common name (CN).
		//if (depth == 0 && preverified) {
		//	X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
		//}
		//	if (verify_subject_alternative_name(hostname, cert)) {
		//		return true;
		//	} else if (verify_common_name(hostname, cert)) {
		//		return true;
		//	} else {
		//		return false;
		//	}
		//}

		return true;	
	}
	
	SecuredClient::context_ptr SecuredClient::onTLSInit(const char * hostname, websocketpp::connection_hdl )
	{
		context_ptr ctx = websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv12);

		try 
		{
			ctx->set_options(boost::asio::ssl::context::default_workarounds |
				boost::asio::ssl::context::no_sslv2 |
				boost::asio::ssl::context::no_sslv3 |
				boost::asio::ssl::context::no_tlsv1 |
				boost::asio::ssl::context::single_dh_use);


			ctx->set_verify_mode(boost::asio::ssl::verify_peer);
			ctx->set_verify_callback(bind(&SecuredClient::onVerifyCertificate, this, hostname, _1, _2));

			// Here we load the CA certificates of all CA's that this client trusts.
			//ctx->load_verify_file("ca-chain.cert.pem");
		} 
		catch (std::exception& e) 
		{
			std::cout << e.what() << std::endl;
		}
		return ctx;
	}

	int SecuredClient::connect() 
	{
		m_thread.reset(new boost::thread(boost::bind(&SecuredClient::runThread, this)));
		return 1;
	}

	void SecuredClient::sendMessage(const std::string& msg)
	{		
		m_client.send(m_connection->get_handle(), msg, websocketpp::frame::opcode::value::TEXT);
	}
	void SecuredClient::disconnect()
	{
		m_client.stop();
		m_thread->join();
		m_thread.reset();
		m_client.reset();
	}
	void SecuredClient::onMessage(websocketpp::connection_hdl hdl, websocketpp::config::asio_client::message_type::ptr msg)
	{
		m_messageHandler.handleMessage(msg->get_payload());

	}
	void SecuredClient::runThread()
	{
		try {
			// Set logging to be pretty verbose (everything except message payloads)
			m_client.set_access_channels(websocketpp::log::alevel::all);
			m_client.clear_access_channels(websocketpp::log::alevel::frame_payload);

			// Initialize ASIO
			m_client.init_asio();

			// Register our message handler
			m_client.set_message_handler(bind(&SecuredClient::onMessage,this, _1,_2));
			m_client.set_tls_init_handler(bind(&SecuredClient::onTLSInit, this, "localhost", _1));

			websocketpp::lib::error_code ec;
			m_connection = m_client.get_connection(m_uri, ec);
			if (ec) {
				std::cout << "could not create connection because: " << ec.message() << std::endl;
			}

			// Note that connect here only requests a connection. No network messages are
			// exchanged until the event loop starts running in the next line.
			m_client.connect(m_connection);

			// Start the ASIO io_service run loop
			// this will cause a single connection to be made to the server. m_client.run()
			// will exit when this connection is closed.
			m_client.run();
		} catch (websocketpp::exception const & e) {
			std::cout << e.what() << std::endl;
		}
	}
}}}

