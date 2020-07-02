#pragma once

#include "WebSocketsAdapterInterface/IServerMessageHandler.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockServerMessageHandler : public IServerMessageHandler
	{
	public:
		MockServerMessageHandler();
		virtual ~MockServerMessageHandler();

		MOCK_METHOD2(handleClientMessage, void(const std::string&, const std::string&));
	};

}}}
