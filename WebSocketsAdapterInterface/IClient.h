#pragma once

#include <memory>
#include <stdexcept>
#include <string>


namespace systelab { namespace websockets_adapter {

	class IClientMessageHandler;

	class IClient
	{
	public:
		virtual ~IClient() = default;

		virtual void registerClientMessageHandler(std::unique_ptr<IClientMessageHandler>) = 0;

		virtual void connect() = 0;
		virtual void disconnect() = 0;

		virtual void sendMessageToServer(const std::string& message) = 0;

	public:
		struct Exception : public std::runtime_error
		{
			Exception(const std::string& message)
				:std::runtime_error(message.c_str())
			{}
		};
	};

}}}
