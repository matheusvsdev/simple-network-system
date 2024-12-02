//
// Created by Matheus Valdevino on 02/12/24.
//

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include "connection.h"

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_service &io_service)
       : io_service_(io_service),
        acceptor_(io_service_, tcp::endpoint(tcp::v4(), 8081)) {
        start_accept();
    }

private:
    void start_accept() {
        std::cout << "Servidor escutando na porta 8081..." << std::endl;
        Connection* connection = new Connection(io_service_);
        acceptor_.async_accept(connection->socket(),
          boost::bind(&Server::handle_accept, this, connection,
          boost::asio::placeholders::error));
    }

    void handle_accept(Connection* connection, const boost::system::error_code& error) {
        if (!error) {
            std::cout << "Conexão aceita de " << connection->socket().remote_endpoint().address() << std::endl;
            connection->start();
        } else {
            std::cout << "Erro ao aceitar conexão: " << error.message() << std::endl;
            delete connection;
        }

        start_accept();
    }

    boost::asio::io_service& io_service_;
    tcp::acceptor acceptor_;
};

int main() {
    boost::asio::io_service io_service;
    Server server(io_service);
    io_service.run();
    return 0;
}
