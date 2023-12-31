#include <boost/asio/io_service.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/deadline_timer.hpp>


#include <amqpcpp.h>
#include "SocketHandler.h"
/**
 *  Main program
 *  @return int
 */
int main()
{
    boost::asio::io_service service(4);

    SocketHandler handler(service);
    
    return service.run();
}

