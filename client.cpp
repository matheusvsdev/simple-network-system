//
// Created by Matheus Valdevino on 02/12/24.
//

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>

using boost::asio::ip::tcp;

class Client {
public:
    Client(boost::asio::io_service &io_service)
        : io_service_(io_service),
          socket_(io_service_) {
        start_connect();
    }

private:
    void start_connect() {
        std::cout << "Cliente se conectando ao servidor na porta 8081..." << std::endl;
        tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8081);
        socket_.async_connect(endpoint,
                              boost::bind(&Client::handle_connect, this, boost::asio::placeholders::error));
    }

    void handle_connect(const boost::system::error_code &error) {
        if (!error) {
            std::cout << "Conexão estabelecida com o servidor!" << std::endl;
            boost::asio::streambuf request;
            std::ostream request_stream(&request);
            request_stream << "Olá, servidor!" << std::endl;

            std::cout << "Enviando mensagem para o servidor..." << std::endl;
            boost::asio::write(socket_, request);
            std::cout << "Mensagem enviada!" << std::endl;
        } else {
            std::cout << "Erro ao se conectar ao servidor: " << error.message() << std::endl;
        }
    }


    boost::asio::io_service &io_service_;
    tcp::socket socket_;
};

int main() {
    boost::asio::io_service io_service;
    Client client(io_service);
    io_service.run();
    return 0;
}
