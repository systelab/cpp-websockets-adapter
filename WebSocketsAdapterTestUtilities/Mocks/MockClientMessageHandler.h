#pragma once

#include "WebSocketsAdapterInterface/IClientMessageHandler.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockClientMessageHandler : public IClientMessageHandler
	{
	public:
		MockClientMessageHandler();
		virtual ~MockClientMessageHandler();

		MOCK_METHOD1(handleServerMessage, void(const std::string&));
	};

}}}
