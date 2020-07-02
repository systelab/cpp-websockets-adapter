[![Build Status](https://travis-ci.org/systelab/cpp-websockets-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-websockets-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/nh73hrkbkcivaprl?svg=true)](https://ci.appveyor.com/project/systelab/cpp-websockets-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cdb01d96abbd49ba92ffb0edcff71988)](https://www.codacy.com/app/systelab/cpp-websockets-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-websockets-adapter&amp;utm_campaign=Badge_Grade)
[![Download](https://api.bintray.com/packages/systelab/conan/WebSocketsAdapterInterface:systelab/images/download.svg)](https://bintray.com/systelab/conan/WebSocketsAdapterInterface:systelab/_latestVersion)


# C++ Web Sockets Adapter

This repository defines a library-agnostic API for C++ to work with a web sockets.

## Supported features

* Server and client
* WSS
* Send messages to server
* Push notifications to all clients

## Available implementations

* [WebSocketppAdapter](https://github.com/systelab/cpp-websocketpp-adapter)

## Usage

Use of this library begins with an instance of:
* `systelab::websockets_adapter::IServerFactory` class (for server features)
* `systelab::websockets_adapter::IClientFactory` class (for client features)

See documentation of selected implementation for details about how to build one.

### WS server set up

Set up a new WS web server by providing a configuration object that specifies the port:

```cpp
systelab::websockets_adapter::ServerConfiguration configuration;
configuration.setPort(8080);

systelab::websockets_adapter::IServerFactory& serverFactory = ...
std::unique_ptr<systelab::websockets_adapter::IServer> server = serverFactory.buildServer(configuration);
```

Finally, start the server calling the `start()` method:

```cpp
server->start();
```

### WSS

WSS can be enabled through the configuration object provided when creating the server. The `systelab::websockets_adapter::ServerSecurityConfiguration` class allows defining the paths of the certificate files as follows:

```cpp
systelab::websockets_adapter::ServerConfiguration configuration;
systelab::websockets_adapter::ServerSecurityConfiguration& securityConfiguration = configuration.getSecurityConfiguration();
securityConfiguration.setWSSEnabled(true);
securityConfiguration.setServerCertificate("Server.cert");
securityConfiguration.setServerPrivateKey("Server.key");
securityConfiguration.setServerDHParam("Server.dhparam");
```

Additionally, support for specific [TLS](https://wiki.openssl.org/index.php/SSL/TLS_Client) versions can be enabled/disabled:

```cpp
securityConfiguration.setTLSv12Enabled(false);
securityConfiguration.setTLSv13Enabled(true);
```

> By default only TLS v1.2 is enabled. TLS v1.3 needs to be enabled on demand because it is not supported before OpenSSL 1.1.1. Older TLS versions should be always disabled as they have known security vulnerabilities.

### Push notifications to clients

In order to send a push notification to all connected clients, simply use the `sendMessageToAllClients()` method of the server:

```cpp
server->sendMessageToAllClients("Content of push notification goes here");
```

### Handle client messages

Client messages received on the server can be handled by creating a class that implements `systelab::websockets_adapter::IServerMessageHandler` interface:

```cpp
class MyServerMessageHandler : public systelab::websockets_adapter::IServerMessageHandler
{
public:
	MyServerMessageHandler() = default;

	void handleClientMessage(const std::string& clientId, const std::string& payload) override
	{
		// Code to handle a client message goes here
	}
};
```

Then, an instance of this handler class needs to be registered on the server:

```cpp
server->registerServerMessageHandler(std::make_unique<MyServerMessageHandler>());
```

### WS/WSS client usage

Set up a new WS client by providing a server IP address and a port number through a configuration object:

```cpp
systelab::websockets_adapter::ClientConfiguration clientConfiguration;
clientConfiguration.setHostAddress("127.0.0.1");
clientConfiguration.setPort(8080);

systelab::websockets_adapter::IClientFactory& clientFactory = ...
std::unique_ptr<systelab::websockets_adapter::IClient> client = clientFactory.buildClient(clientConfiguration);
```

Similarly, an WSS client can be created by indicating so on the configuration:

```cpp
clientConfiguration.setUseWSS(true);
```

Then, the returned `systelab::websockets_adapter::IClient` object can be used to send messages to the server:

```cpp
client->sendMessageToServer("This is a message for the server");
```

Server messages can be handled by creating a class that implements `systelab::websockets_adapter::IClientMessageHandler` interface and registering it to the client as follows:

```cpp
class MyClientMessageHandler : public systelab::websockets_adapter::IClientMessageHandler
{
public:
	MyClientMessageHandler() = default;

	void handleServerMessage(const std::string& payload) override
	{
		// Code to handle a server message goes here
	}
};

client->registerClientMessageHandler(std::make_unique<MyClientMessageHandler>());
```
