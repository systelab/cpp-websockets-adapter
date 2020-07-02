#include "ServerSecurityConfiguration.h"


namespace systelab { namespace websockets_adapter {

	ServerConfiguration::ServerConfiguration()
		:m_port(80)
		,m_securityConfiguration(std::make_unique<ServerSecurityConfiguration>())
	{
	}

	ServerConfiguration::ServerConfiguration(const ServerConfiguration& other)
		:m_port(other.m_port)
		,m_securityConfiguration(std::make_unique<ServerSecurityConfiguration>(*other.m_securityConfiguration))
	{
	}

	ServerConfiguration::~ServerConfiguration() = default;

	unsigned int ServerConfiguration::getPort() const
	{
		return m_port;
	}

	void ServerConfiguration::setPort(unsigned int port)
	{
		m_port = port;
	}

	const ServerSecurityConfiguration& ServerConfiguration::getSecurityConfiguration() const
	{
		return *m_securityConfiguration;
	}

	ServerSecurityConfiguration& ServerConfiguration::getSecurityConfiguration()
	{
		return *m_securityConfiguration;
	}

	ServerConfiguration& ServerConfiguration::operator= (const ServerConfiguration& other)
	{
		m_port = other.m_port;
		*m_securityConfiguration = *other.m_securityConfiguration;

		return *this;
	}

}}
