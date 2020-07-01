#ifndef _TESTUTILITIES_WEBSOCKETSADAPTER_MOCKMESSAGEHANDLER_QUIM_VILA_3101181021_H
#define _TESTUTILITIES_WEBSOCKETSADAPTER_MOCKMESSAGEHANDLER_QUIM_VILA_3101181021_H

#include "WebSocketsAdapterTestUtilities/IMessageHandler.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockMessageHandler : public IMessageHandler
	{
	public:
		MockMessageHandler() {};
		virtual ~MockMessageHandler() {};

		MOCK_METHOD1(handleMessage, void(const std::string&));
	};

}}}

#endif //_TESTUTILITIES_WEBSOCKETSADAPTER_MOCKMESSAGEHANDLER_QUIM_VILA_3101181021_H
