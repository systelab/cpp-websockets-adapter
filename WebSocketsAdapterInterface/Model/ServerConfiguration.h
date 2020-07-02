#pragma once

#include <memory>
#include <string>


namespace systelab { namespace websockets_adapter {

	class ServerSecurityConfiguration;

	class ServerConfiguration
	{
	public:
		inline ServerConfiguration();
		inline ServerConfiguration(const ServerConfiguration&);
		inline virtual ~ServerConfiguration();

		inline unsigned int getPort() const;
		inline void setPort(unsigned int);

		inline const ServerSecurityConfiguration& getSecurityConfiguration() const;
		inline ServerSecurityConfiguration& getSecurityConfiguration();

		inline ServerConfiguration& operator= (const ServerConfiguration& other);

	private:
		unsigned int m_port;
		std::unique_ptr<ServerSecurityConfiguration> m_securityConfiguration;
	};

}}

#include "ServerConfiguration.inl"
