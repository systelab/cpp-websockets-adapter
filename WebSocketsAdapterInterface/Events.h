#ifndef _WEBSOCKETSADAPTERINTERFACE_EVENTS_QUIM_VILA_3001181907_H
#define _WEBSOCKETSADAPTERINTERFACE_EVENTS_QUIM_VILA_3001181907_H

#include "SystelabUtils/systelab/utils/patterns/PublisherSubscriber/Event.h"


namespace systelab { namespace websockets_adapter {

	namespace sup = systelab::utils::patterns;

	const sup::EventType MESSAGE_RECEIVED_EVENT = "WEBSOCKETS_MESSAGE_RECEIVED";
	struct MessageReceivedEvent : sup::Event
	{
		MessageReceivedEvent(const std::string& payload)
			: m_payload(payload)
		{
			m_name = MESSAGE_RECEIVED_EVENT;
		}

	public:
		std::string m_payload;
	};

}}

#endif //_WEBSOCKETSADAPTERINTERFACE_EVENTS_QUIM_VILA_3001181907_H