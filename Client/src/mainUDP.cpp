# include <iostream>
# include "Client.h"
# include "CUDPNetworkHandler.hh"
# include "ViewController.h"
# include "AssetsController.h"
# include "NetworkDefines.h"
# include "FirePacket.h"
ViewController *vc;
AssetsController *ac;

int main(int ac, char **av)
{
  CUDPNetworkHandler			*nh = new CUDPNetworkHandler("127.0.0.1", av[1]);
  std::string				str;
  IServerPacket<ServerUDPResponse>	*packet;


  nh->initSocket();
  while (1)
    {
      std::getline(std::cin, str);
      int i = std::atoi(str.c_str());
      switch (i)
      	{
	case 1:
	  nh->send(new CAuthUDPPacket(CAUTH_UDP, 0, "toto"));
	  break;
	case 2:
	  nh->send(new FirePacket(FIRE, 1, (float)10, (float)10));
	  break;
	default:
	  break;
      	}
      if (nh->selectServer())
	packet = nh->receive();
    }
}
