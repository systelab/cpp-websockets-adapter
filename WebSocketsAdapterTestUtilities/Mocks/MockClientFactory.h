#pragma once

#include "WebSocketsAdapterInterface/IClientFactory.h"
#include "WebSocketsAdapterInterface/IClient.h"
#include "WebSocketsAdapterInterface/Model/ClientConfiguration.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockClientFactory : public IClientFactory
	{
	public:
		MockClientFactory();
		virtual ~MockClientFactory();

		MOCK_CONST_METHOD1(buildClientProxy, IClient*(const ClientConfiguration&));
		std::unique_ptr<IClient> buildClient(const ClientConfiguration& configuration) const override
		{
			return std::unique_ptr<IClient>(buildClientProxy(configuration));
		}
	};

}}}
