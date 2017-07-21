#pragma once

#include "common.h"


class chat
{
public:
	chat(size_t id);
	~chat();
	void send_private_message(std::string msg, size_t target_id);
	void send_msg_to_server(std::string);
private:
	size_t _id;
	boost::asio::io_service io_service;
	boost::asio::ip::tcp::resolver::iterator endpoint_iterator;
};