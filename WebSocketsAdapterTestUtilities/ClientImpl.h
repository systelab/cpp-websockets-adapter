#ifndef _TESTUTILITIES_WEBSOCKETSADAPTER_CLIENTIMPL_QUIM_VILA_3101181115_H
#define _TESTUTILITIES_WEBSOCKETSADAPTER_CLIENTIMPL_QUIM_VILA_3101181115_H

// This code comes from:
// https://github.com/dhbaird/easywsclient
//
// To get the latest version:
// wget https://raw.github.com/dhbaird/easywsclient/master/easywsclient.hpp
// wget https://raw.github.com/dhbaird/easywsclient/master/easywsclient.cpp

#include <string>
#include <vector>

namespace systelab { namespace websockets_adapter { namespace test_utility {

	struct Callback_Imp { virtual void operator()(const std::string& message) = 0; };
	struct BytesCallback_Imp { virtual void operator()(const std::vector<uint8_t>& message) = 0; };

	class ClientImpl
	{
	public:
		typedef ClientImpl* pointer;
		typedef enum readyStateValues { CLOSING, CLOSED, CONNECTING, OPEN } readyStateValues;

		// Factories:
		static pointer create_dummy();
		static pointer from_url(const std::string& url, const std::string& origin = std::string());
		static pointer from_url_no_mask(const std::string& url, const std::string& origin = std::string());

		// Interfaces:
		virtual ~ClientImpl() { }
		virtual void poll(int timeout = 0) = 0; // timeout in milliseconds
		virtual void send(const std::string& message) = 0;
		virtual void sendBinary(const std::string& message) = 0;
		virtual void sendBinary(const std::vector<uint8_t>& message) = 0;
		virtual void sendPing() = 0;
		virtual void close() = 0;
		virtual readyStateValues getReadyState() const = 0;

		template<class Callable>
		void dispatch(Callable callable)
			// For callbacks that accept a string argument.
		{ // N.B. this is compatible with both C++11 lambdas, functors and C function pointers
			struct _Callback : public Callback_Imp {
				Callable& callable;
				_Callback(Callable& callable) : callable(callable) { }
				void operator()(const std::string& message) { callable(message); }
			};
			_Callback callback(callable);
			_dispatch(callback);
		}

		template<class Callable>
		void dispatchBinary(Callable callable)
			// For callbacks that accept a std::vector<uint8_t> argument.
		{ // N.B. this is compatible with both C++11 lambdas, functors and C function pointers
			struct _Callback : public BytesCallback_Imp {
				Callable& callable;
				_Callback(Callable& callable) : callable(callable) { }
				void operator()(const std::vector<uint8_t>& message) { callable(message); }
			};
			_Callback callback(callable);
			_dispatchBinary(callback);
		}

	protected:
		virtual void _dispatch(Callback_Imp& callable) = 0;
		virtual void _dispatchBinary(BytesCallback_Imp& callable) = 0;
	};

}}}

#endif /* _TESTUTILITIES_WEBSOCKETSADAPTER_CLIENTIMPL_QUIM_VILA_3101181115_H */
