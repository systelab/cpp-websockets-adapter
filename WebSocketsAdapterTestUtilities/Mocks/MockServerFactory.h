#pragma once

#include "WebSocketsAdapterInterface/IServerFactory.h"
#include "WebSocketsAdapterInterface/IServer.h"
#include "WebSocketsAdapterInterface/Model/ServerConfiguration.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockServerFactory : public IServerFactory
	{
	public:
		MockServerFactory();
		virtual ~MockServerFactory();

		MOCK_CONST_METHOD1(buildServerProxy, IServer*(const ServerConfiguration&));
		std::unique_ptr<IServer> buildServer(const ServerConfiguration& configuration) const override
		{
			return std::unique_ptr<IServer>(buildServerProxy(configuration));
		}
	};

}}}
