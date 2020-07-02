#pragma once

#include <string>


namespace systelab { namespace websockets_adapter {

	class ServerSecurityConfiguration
	{
	public:
		inline ServerSecurityConfiguration();
		inline ServerSecurityConfiguration(const ServerSecurityConfiguration&);
		inline virtual ~ServerSecurityConfiguration();

		inline bool isWSSEnabled() const;
		inline std::string getServerCertificate() const;
		inline std::string getServerPrivateKey() const;
		inline std::string getServerDHParam() const;

		inline bool isTLSv10Enabled() const;
		inline bool isTLSv11Enabled() const;
		inline bool isTLSv12Enabled() const;
		inline bool isTLSv13Enabled() const;

		inline void setWSSEnabled(bool);
		inline void setServerCertificate(const std::string&);
		inline void setServerPrivateKey(const std::string&);
		inline void setServerDHParam(const std::string&);

		inline void setTLSv10Enabled(bool);
		inline void setTLSv12Enabled(bool);
		inline void setTLSv13Enabled(bool);
		inline void setTLSv11Enabled(bool);

		inline ServerSecurityConfiguration& operator= (const ServerSecurityConfiguration&);

	private:
		bool m_wssEnabled;
		std::string m_serverCertificate;
		std::string m_serverPrivateKey;
		std::string m_serverDHParam;
		
		bool m_tlsv10Enabled;
		bool m_tlsv11Enabled;
		bool m_tlsv12Enabled;
		bool m_tlsv13Enabled;
	};

}}

#include "ServerSecurityConfiguration.inl"

