#include "common.h"


int main()
{

	boost::asio::io_service io_service;
	boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(
	boost::asio::ip::tcp::v4(), CONST_VAL::HOST_PORT_INT));
	while (true) {
		boost::asio::ip::tcp::socket socket(io_service);
		acceptor.accept(socket);
		std::cout << "connected with client, waiting for a message\n";
		std::string message;
		read_message(message, socket);
		boost::asio::ip::tcp::endpoint endpoint = socket.remote_endpoint();
		std::cout << "message received from " << endpoint.address().to_string() <<
			':' << endpoint.port() << '\n' << message << '\n';
		boost::asio::write(socket, boost::asio::buffer(message + '\0'));
		if (message.compare("quit") == 0)
		{
			break;
		}
	}
	return EXIT_SUCCESS;
}