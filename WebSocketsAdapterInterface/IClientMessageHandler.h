#pragma once

#include <string>


namespace systelab { namespace websockets_adapter {

	class IClientMessageHandler
	{
	public:
		virtual ~IClientMessageHandler() = default;

		virtual void handleServerMessage(const std::string& payload) = 0;
	};

}}
