
namespace systelab { namespace websockets_adapter {

	ServerSecurityConfiguration::ServerSecurityConfiguration()
		:m_wssEnabled(false)
		,m_serverCertificate("")
		,m_serverPrivateKey("")
		,m_serverDHParam("")
		,m_tlsv10Enabled(false)
		,m_tlsv11Enabled(false)
		,m_tlsv12Enabled(true)
		,m_tlsv13Enabled(false)
	{
	}

	ServerSecurityConfiguration::ServerSecurityConfiguration(const ServerSecurityConfiguration& other)
		:m_wssEnabled(other.m_wssEnabled)
		,m_serverCertificate(other.m_serverCertificate)
		,m_serverPrivateKey(other.m_serverPrivateKey)
		,m_serverDHParam(other.m_serverDHParam)
		,m_tlsv10Enabled(other.m_tlsv10Enabled)
		,m_tlsv11Enabled(other.m_tlsv11Enabled)
		,m_tlsv12Enabled(other.m_tlsv12Enabled)
		,m_tlsv13Enabled(other.m_tlsv13Enabled)
	{
	}

	ServerSecurityConfiguration::~ServerSecurityConfiguration() = default;

	bool ServerSecurityConfiguration::isWSSEnabled() const
	{
		return m_wssEnabled;
	}

	std::string ServerSecurityConfiguration::getServerCertificate() const
	{
		return m_serverCertificate;
	}

	std::string ServerSecurityConfiguration::getServerPrivateKey() const
	{
		return m_serverPrivateKey;
	}

	std::string ServerSecurityConfiguration::getServerDHParam() const
	{
		return m_serverDHParam;
	}

	bool ServerSecurityConfiguration::isTLSv10Enabled() const
	{
		return m_tlsv10Enabled;
	}

	bool ServerSecurityConfiguration::isTLSv11Enabled() const
	{
		return m_tlsv11Enabled;
	}

	bool ServerSecurityConfiguration::isTLSv12Enabled() const
	{
		return m_tlsv12Enabled;
	}

	bool ServerSecurityConfiguration::isTLSv13Enabled() const
	{
		return m_tlsv13Enabled;
	}

	void ServerSecurityConfiguration::setWSSEnabled(bool wssEnabled)
	{
		m_wssEnabled = wssEnabled;
	}

	void ServerSecurityConfiguration::setServerCertificate(const std::string& serverCertificate)
	{
		m_serverCertificate = serverCertificate;
	}

	void ServerSecurityConfiguration::setServerPrivateKey(const std::string& serverPrivateKey)
	{
		m_serverPrivateKey = serverPrivateKey;
	}

	void ServerSecurityConfiguration::setServerDHParam(const std::string& serverDHParam)
	{
		m_serverDHParam = serverDHParam;
	}

	void ServerSecurityConfiguration::setTLSv10Enabled(bool tlsv10Enabled)
	{
		m_tlsv10Enabled = tlsv10Enabled;
	}
	
	void ServerSecurityConfiguration::setTLSv11Enabled(bool tlsv11Enabled)
	{
		m_tlsv11Enabled = tlsv11Enabled;
	}
	
	void ServerSecurityConfiguration::setTLSv12Enabled(bool tlsv12Enabled)
	{
		m_tlsv12Enabled = tlsv12Enabled;
	}
	
	void ServerSecurityConfiguration::setTLSv13Enabled(bool tlsv13Enabled)
	{
		m_tlsv13Enabled = tlsv13Enabled;
	}

	ServerSecurityConfiguration& ServerSecurityConfiguration::operator= (const ServerSecurityConfiguration& other)
	{
		m_wssEnabled = other.m_wssEnabled;
		m_serverCertificate = other.m_serverCertificate;
		m_serverPrivateKey = other.m_serverPrivateKey;
		m_serverDHParam = other.m_serverDHParam;
		m_tlsv10Enabled = other.m_tlsv10Enabled;
		m_tlsv11Enabled = other.m_tlsv11Enabled;
		m_tlsv12Enabled = other.m_tlsv12Enabled;
		m_tlsv13Enabled = other.m_tlsv13Enabled;

		return *this;
	}

}}