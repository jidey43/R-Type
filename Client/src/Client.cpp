#include "Client.h"

#include <iostream>
#include "NetworkDefines.h"


Client::Client(std::string const & ip, std::string const & port)
	: _network(new CNetworkHandler(ip, port))
{
  if (_network->initSocket())
    {
      std::string		str;
      // std::cout << "Client started" << std::endl;
      // std::getline(std::cin, str);
      // _network->sendToServer(str);
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

  while (1)
    {
      std::getline(std::cin, str);
      int i = std::atoi(str.c_str());
      switch (i)
      	{
	case 1:
	  _network->sendToServer(new NewGamePacket(ADD_GAME, "lalalalallal"));
	case 2:
	  _network->sendToServer(new NickPacket(AUTH_TCP, "lalla"));
	// case 2:
	//   _network->sendToServer()
      	}
      _network->receiveFromServer();
      // std::cout << "SERVER : " << _network->getPacket() << std::endl;
    }
}
