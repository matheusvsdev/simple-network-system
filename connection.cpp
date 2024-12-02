//
// Created by Matheus Valdevino on 02/12/24.
//

#include "connection.h"
#include <iostream>

Connection::Connection(boost::asio::io_service& io_service)
  : socket_(io_service) {}

void Connection::start() {
    boost::asio::streambuf request;
    boost::asio::read_until(socket_, request, '\n');

    std::cout << "Mensagem recebida do cliente!" << std::endl;
    std::istream request_stream(&request);
    std::string mensagem;
    request_stream >> mensagem;

    std::cout << "Mensagem do cliente: " << mensagem << std::endl;

    // Adicione uma mensagem de depuração aqui para verificar se a mensagem está sendo lida corretamente
    std::cout << "Tamanho da mensagem: " << request.size() << std::endl;
}


tcp::socket& Connection::socket() {
    return socket_;
}


