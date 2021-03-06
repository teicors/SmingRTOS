/****
 * Sming Framework Project - Open Source framework for high efficiency native ESP8266 development.
 * Created 2015 by Skurydin Alexey
 * http://github.com/anakod/Sming
 * All files of the Sming Core are provided under the LGPL v3 license.
 ****/

#ifndef SMINGCORE_NETWORK_WEBSOCKET_H_
#define SMINGCORE_NETWORK_WEBSOCKET_H_

#include "TcpServer.h"
#include "HttpServerConnection.h"
#include "../wiring/WHashMap.h"
#include "../wiring/WVector.h"
#include "../core/Delegate.h"
#include "../services/cWebsocket/websocket.h"

class HttpServer;
class CommandExecutor;

class WebSocket
{
	friend class HttpServer;
public:
	WebSocket(HttpServerConnection* conn);
	~WebSocket();

	virtual void send(const char* message, int length, wsFrameType type = WS_TEXT_FRAME);
	void sendString(const String& message);
	void sendBinary(const uint8_t* data, int size);
	void enableCommand();

protected:
	bool initialize(HttpRequest &request, HttpResponse &response);
	bool is(HttpServerConnection* conn) { return connection == conn; };

private:
	HttpServerConnection* connection;
	CommandExecutor* commandExecutor = nullptr;
};

#endif /* SMINGCORE_NETWORK_WEBSOCKET_H_ */
