#pragma once

#include <string>


namespace systelab { namespace websockets_adapter {

	class IServerMessageHandler
	{
	public:
		virtual ~IServerMessageHandler() = default;

		virtual void handleClientMessage(const std::string& clientId, const std::string& payload) = 0;
	};

}}
