//
// Created by Matheus Valdevino on 02/12/24.
//

#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Connection {
public:
    Connection(boost::asio::io_service& io_service);
    void start();
    tcp::socket& socket();

private:
    tcp::socket socket_;
};

#endif  // CONNECTION_H
