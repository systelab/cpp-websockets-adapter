#pragma once

#include <memory>
#include <stdexcept>
#include <string>


namespace systelab { namespace websockets_adapter {

	class IServerMessageHandler;

	class IServer
	{
	public:
		virtual ~IServer() = default;

		virtual void registerServerMessageHandler(std::unique_ptr<IServerMessageHandler>) = 0;

		virtual bool isRunning() const = 0;
		virtual void start() = 0;
		virtual void stop() = 0;

		virtual void sendMessageToAllClients(const std::string& payload) = 0;

	public:
		struct Exception : public std::runtime_error
		{
			Exception(const std::string& message)
				:std::runtime_error(message.c_str())
			{}
		};
	};

}}
