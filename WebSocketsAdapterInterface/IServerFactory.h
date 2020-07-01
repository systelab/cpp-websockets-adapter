#pragma once

namespace systelab { namespace websockets_adapter {

	class IServer;

	class IServerFactory
	{
	public:
		virtual ~IServerFactory() {};

		virtual std::unique_ptr<IServer> buildServer(bool useWSS) const = 0;
	};

}}
