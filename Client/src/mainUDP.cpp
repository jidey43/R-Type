# include <iostream>
# include "Client.h"
# include "CUDPNetworkHandler.hh"
# include "ViewController.h"
# include "AssetsController.h"
# include "NetworkDefines.h"

ViewController *vc;
AssetsController *ac;

int main(int ac, char **av)
{
  CUDPNetworkHandler *nh = new CUDPNetworkHandler("127.0.0.1", av[1]);
  std::string		str;
  std::string		str2;

  nh->initSocket();
  while (1)
    {
      std::getline(std::cin, str);
      str2 = str.substr(str.find(" "), std::string::npos);
      int i = std::atoi(str.c_str());
      switch (i)
      	{
	case 1:
	  _network->sendToServer(new CAuthUDPPacket(CAUTH_UDP, 0, "toto"));
	  _network->receiveFromServer();
	  break;
	case 2:
	  _network->sendToServer(new FirePacket(AUTH_TCP, 10, 10));
	  _network->receiveFromServer();
	  break;
	// case 2:
	//   _network->sendToServer()
      	}
      // std::cout << "SERVER : " << _network->getPacket() << std::endl;
    }
}
