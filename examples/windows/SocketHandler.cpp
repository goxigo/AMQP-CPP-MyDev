#include "SocketHandler.h"

SocketHandler::SocketHandler(boost::asio::io_service& service)
{
}

void SocketHandler::onData(AMQP::Connection* connection, const char* buffer, size_t size)
{
}
