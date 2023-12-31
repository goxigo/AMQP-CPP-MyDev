#pragma once
#include <boost/asio/io_service.hpp>
#include "amqpcpp.h"

class SocketHandler:public AMQP::ConnectionHandler
{
public:

	SocketHandler(boost::asio::io_service & service);

	// 通过 ConnectionHandler 继承
	void onData(AMQP::Connection* connection, const char* buffer, size_t size) override;
};

