#include "Client.h"

#include <iostream>
#include "NetworkDefines.h"


Client::Client(std::string const & ip, std::string const & port)
	: _network(new NetworkHandler(ip, port)), _packet(new ClientPacket)
{
	if (_network->initSocket())
	{
		std::string		str;
		std::cout << "Client strated" << std::endl;
		std::cin >> str;
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

	std::cout << "lol" << std::endl;
	while (1)
	{
		std::cin >> str;
			str = "CRE_GAME lala";
		_network->sendToServer(str);
		_network->receiveFromServer();
		std::cout << "SERVER : " << _network->getPacket() << std::endl;
	}
}
