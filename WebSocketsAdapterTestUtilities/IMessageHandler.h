#ifndef _TESTUTILITIES_WEBSOCKETSADAPTER_IMESSAGEHANDLER_QUIM_VILA_3101181019_H
#define _TESTUTILITIES_WEBSOCKETSADAPTER_IMESSAGEHANDLER_QUIM_VILA_3101181019_H

#include <string>

namespace systelab { namespace websockets_adapter { namespace test_utility {

	class IMessageHandler
	{
	public:
		virtual ~IMessageHandler() {};

		virtual void handleMessage(const std::string& message) = 0;
	};

}}}

#endif //_TESTUTILITIES_WEBSOCKETSADAPTER_IMESSAGEHANDLER_QUIM_VILA_3101181019_H
