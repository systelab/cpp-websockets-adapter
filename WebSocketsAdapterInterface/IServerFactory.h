#pragma once

#include <memory>


namespace systelab { namespace websockets_adapter {

	class IServer;
	class ServerConfiguration;

	class IServerFactory
	{
	public:
		virtual ~IServerFactory() = default;

		virtual std::unique_ptr<IServer> buildServer(const ServerConfiguration&) const = 0;
	};

}}
