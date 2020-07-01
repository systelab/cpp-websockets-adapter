[![Build Status](https://travis-ci.org/systelab/cpp-websockets-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-websockets-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/b2yacbbo5x9hp8cy?svg=true)](https://ci.appveyor.com/project/systelab/cpp-websockets-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cdb01d96abbd49ba92ffb0edcff71988)](https://www.codacy.com/app/systelab/cpp-websockets-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-websockets-adapter&amp;utm_campaign=Badge_Grade)
[![Download](https://api.bintray.com/packages/systelab/conan/WebSocketsAdapterInterface:systelab/images/download.svg)](https://bintray.com/systelab/conan/WebSocketsAdapterInterface:systelab/_latestVersion)

# C++ Web Sockets Adapter

This repository defines a library-agnostic API for C++ to work with a web sockets.

## Supported features

* Server and client
* WSS
* Client signals
* Push notifications

## Available implementations

* [WebSocketppAdapter](https://github.com/systelab/cpp-websocketpp-adapter)

## Usage

Use of this library begins with an instance of:
* `systelab::websockets_adapter::IServerFactory` class (for server features)
* `systelab::websockets_adapter::IClientFactory` class (for client features)

See documentation of selected implementation for details about how to build one.

### WS server set up

Set up a new WS web server by providing a configuration object that specifies host address and port:

```cpp
systelab::websockets_adapter::Configuration configuration;
configuration.setHostAddress("127.0.0.1");
configuration.setPort(8080);

systelab::websockets_adapter::IServerFactory& serverFactory = ...
std::unique_ptr<systelab::websockets_adapter::IServer> server = serverFactory.buildServer(configuration);
```

Finally, start the server calling the `start()` method:

```cpp
webServer->start();
```

### WSS

HTTPS can be enabled through the configuration object provided when creating the server. The `systelab::websockets_adapter::SecurityConfiguration` class allows defining the paths of the certificate files as follows:

```cpp
systelab::websockets_adapter::Configuration configuration;
systelab::websockets_adapter::SecurityConfiguration& securityConfiguration = configuration.getSecurityConfiguration();
securityConfiguration.setHTTPSEnabled(true);
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


### WS/WSS client usage

Set up a new WS client by providing a server IP address and a port number:

```cpp
systelab::websockets_adapter::IClientFactory& clientFactory = ...
std::unique_ptr<systelab::websockets_adapter::IClient> client = clientFactory.buildClient("127.0.0.1", 8080, false);
```

Similarly, an WSS client can be created as follows:

```cpp
systelab::websockets_adapter::IClientFactory& clientFactory = ...
std::unique_ptr<systelab::websockets_adapter::IClient> client = clientFactory.buildClient("localhost", 9090, true);
```

Then, the returned `systelab::websockets_adapter::IClient` object can be used to send requests to the server:

```cpp
systelab::websockets_adapter::Request request;
request.setMethod("POST");
request.setURI("/rest/api/login"); 
request.setContent("PasswordGoesHere");
request.getHeaders().addHeader("Content-Type", "text/plain");

std::unique_ptr<Reply> reply = client->send(request);

systelab::websockets_adapter::Reply::StatusType status = reply->getStatus();
std::map<std::string, std::string> headers = reply->getHeaders();
std::string content = reply->getContent();
```
