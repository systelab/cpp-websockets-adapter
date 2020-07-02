#pragma once

#include "WebSocketsAdapterInterface/IServer.h"
#include "WebSocketsAdapterInterface/IServerMessageHandler.h"

namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockServer : public IServer
	{
	public:
		MockServer();
		virtual ~MockServer();

		MOCK_METHOD1(registerServerMessageHandlerProxy, void(IServerMessageHandler*));
		void registerServerMessageHandler(std::unique_ptr<IServerMessageHandler> messageHandler) override
		{
			registerServerMessageHandlerProxy(messageHandler.release());
		}

		MOCK_CONST_METHOD0(isRunning, bool());
		MOCK_METHOD0(start, void());
		MOCK_METHOD0(stop, void());

		MOCK_METHOD1(sendMessageToAllClients, void(const std::string&));
	};

}}}
