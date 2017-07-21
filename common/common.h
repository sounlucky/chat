#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <set>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

inline void read_message(std::string& message, boost::asio::ip::tcp::socket& socket)
{
	std::stringstream message_stream;
	boost::asio::streambuf buffer;
	boost::system::error_code error;
	size_t len = read_until(socket, buffer, '\0', error);
	if (len)
	{
		message_stream.write(boost::asio::buffer_cast<const char *>(buffer.data()), len);
		message = message_stream.str();
	}
}

class CONST_VAL {
public:
	constexpr static char* HOST_IP = "localhost";
	constexpr static char* HOST_PORT_STR = "10674";
	constexpr static int HOST_PORT_INT = 10674;
private:
	CONST_VAL() { } 
	~CONST_VAL() {  } 
	CONST_VAL(CONST_VAL const&); 
	CONST_VAL& operator= (CONST_VAL const&); 
};