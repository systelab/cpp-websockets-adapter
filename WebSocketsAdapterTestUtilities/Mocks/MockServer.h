#ifndef _TESTUTILITIES_WEBSOCKETSADAPTER_MOCKSERVER_QUIM_VILA_3101181107_H
#define _TESTUTILITIES_WEBSOCKETSADAPTER_MOCKSERVER_QUIM_VILA_3101181107_H

#include "WebSocketsAdapterInterface/IServer.h"


namespace systelab { namespace websockets_adapter { namespace test_utility {

	class MockServer : public IServer
	{
	public:
		MockServer() {};
		virtual ~MockServer() {};

		MOCK_METHOD1(run, void(unsigned int));
		MOCK_METHOD0(stop, void());

		MOCK_METHOD1(pushNotification, void(const std::string&));
		MOCK_METHOD1(setServerCredentials, void(const Credentials&));
	};

}}}

#endif //_TESTUTILITIES_WEBSOCKETSADAPTER_MOCKSERVER_QUIM_VILA_3101181107_H
