#pragma once

#include <string>

namespace systelab { namespace websockets_adapter {

	struct ServerException: public std::runtime_error 
	{
		ServerException(const std::string& message) : std::runtime_error(message.c_str()) {}
	};

	class IServer
	{
	public:
		struct Credentials
		{
			std::string certificate;
			std::string privateKey;
			std::string dhParam;
		};

		virtual ~IServer() {};

		virtual void run(unsigned int port) = 0;
		virtual void stop() = 0;

		virtual void pushNotification(const std::string& payload) = 0;
		virtual void setServerCredentials(const Credentials& credentials) = 0;
	};

}}
