#pragma once

#include <memory>
#include <string>


namespace systelab { namespace websockets_adapter {

	class ClientConfiguration
	{
	public:
		inline ClientConfiguration();
		inline ClientConfiguration(const ClientConfiguration&);
		inline virtual ~ClientConfiguration();

		inline std::string getHostAddress() const;
		inline unsigned int getPort() const;
		inline bool isUsingWSS() const;

		inline void setHostAddress(const std::string&);
		inline void setPort(unsigned int);
		inline void setUseWSS(bool);

		inline ClientConfiguration& operator= (const ClientConfiguration& other);

	private:
		std::string m_hostAddress;
		unsigned int m_port;
		bool m_useWSS;
	};

}}

#include "ClientConfiguration.inl"
