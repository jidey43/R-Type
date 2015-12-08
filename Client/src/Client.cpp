#include "Client.h"

#include <iostream>
#include "NetworkDefines.h"


Client::Client(std::string const & ip, std::string const & port)
	: _network(new NetworkHandler(ip, port)), _packet(new ClientPacket)
{
	if (_network->initSocket())
	{
		std::string		str;
		std::cout << "Client started" << std::endl;
		std::getline(std::cin, str);
		_network->sendToServer(str);
		start();
	}
}

Client::~Client()
{
	delete _network;
}

void Client::start()
{
	std::string		str;
	std::string		str2;

	while (1)
	{
	  std::getline(std::cin, str);
	  _network->sendToServer(str);
	  _network->receiveFromServer();
	  std::cout << "SERVER : " << _network->getPacket() << std::endl;
	}
}
