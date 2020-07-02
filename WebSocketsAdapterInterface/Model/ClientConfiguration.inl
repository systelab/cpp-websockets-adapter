
namespace systelab { namespace websockets_adapter {

	ClientConfiguration::ClientConfiguration()
		:m_hostAddress("127.0.0.1")
		,m_port(80)
		,m_useWSS(false)
	{
	}

	ClientConfiguration::ClientConfiguration(const ClientConfiguration& other)
		:m_hostAddress(other.m_hostAddress)
		,m_port(other.m_port)
		,m_useWSS(other.m_useWSS)
	{
	}

	ClientConfiguration::~ClientConfiguration() = default;

	std::string ClientConfiguration::getHostAddress() const
	{
		return m_hostAddress;
	}

	unsigned int ClientConfiguration::getPort() const
	{
		return m_port;
	}
	
	bool ClientConfiguration::isUsingWSS() const
	{
		return m_useWSS;
	}

	void ClientConfiguration::setHostAddress(const std::string& hostAddress)
	{
		m_hostAddress = hostAddress;
	}

	void ClientConfiguration::setPort(unsigned int port)
	{
		m_port = port;
	}

	void ClientConfiguration::setUseWSS(bool useWSS)
	{
		m_useWSS = useWSS;
	}

	ClientConfiguration& ClientConfiguration::operator= (const ClientConfiguration& other)
	{
		m_hostAddress = other.m_hostAddress;
		m_port = other.m_port;
		m_useWSS = other.m_useWSS;

		return *this;
	}

}}
