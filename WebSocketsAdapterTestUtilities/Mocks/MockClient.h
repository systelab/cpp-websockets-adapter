#pragma once

#include "WebSocketsAdapterInterface/IClient.h"
#include "WebSocketsAdapterInterface/IClientMessageHandler.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockClient : public IClient
	{
	public:
		MockClient();
		virtual ~MockClient();

		MOCK_METHOD1(registerClientMessageHandlerProxy, void(IClientMessageHandler*));
		void registerClientMessageHandler(std::unique_ptr<IClientMessageHandler> messageHandler) override
		{
			registerClientMessageHandlerProxy(messageHandler.release());
		}

		MOCK_METHOD0(connect, void());
		MOCK_METHOD0(disconnect, void());

		MOCK_METHOD1(sendMessageToServer, void(const std::string&));
	};

}}}
