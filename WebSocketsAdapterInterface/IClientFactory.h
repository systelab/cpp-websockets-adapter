#pragma once

#include <memory>


namespace systelab { namespace websockets_adapter {

	class ClientConfiguration;
	class IClient;

	class IClientFactory
	{
	public:
		virtual ~IClientFactory() = default;

		virtual std::unique_ptr<IClient> buildClient(const ClientConfiguration&) const = 0;
	};

}}
