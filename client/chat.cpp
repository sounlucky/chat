#pragma once
#include "chat.h"

chat::chat(size_t id): _id(id){
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query(CONST_VAL::HOST_IP, CONST_VAL::HOST_PORT_STR);
	endpoint_iterator = resolver.resolve(query);
}


chat::~chat()
{
}

void chat::send_private_message(std::string msg, size_t target_id) {
}

void chat::send_msg_to_server(std::string message) {

	boost::asio::ip::tcp::socket socket(io_service);
	boost::asio::connect(socket, endpoint_iterator);
	boost::asio::write(socket, boost::asio::buffer(message + '\0'));
}