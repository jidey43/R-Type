# include <iostream>
# include "ViewController.hh"
# include "Manager.hh"
# include "MenuController.hh"
# include "AssetsController.hh"
# include "CNetworkHandler.hh"
# include "CUDPNetworkHandler.hh"

ViewController *vc;
AssetsController *ac;

int main(int argc, char **av)
{
  ac = new AssetsController("../../assets/");
  if (ac->loadAssets() == false)
    {
      std::cerr << "assets could not be loaded, aborting . . ." << std::endl;
      return -1;
    }

  vc = new ViewController;

  Manager *m;
  MenuController *menu;
  CNetworkHandler *tcpHand;

  while (true)
    {
      menu = new MenuController(&tcpHand);
      menu->loop();

      //
      //
      // INIT DU UDP A LA MAIN
      IServerPacket<ServerTCPResponse> *response;
      if (av[1])
    	tcpHand->sendToServer(new NewGamePacket(ADD_GAME, "Game de l'espace"));
      else
     	tcpHand->sendToServer(new JoinPacket(JOIN_GAME, 13));
      response = tcpHand->receiveFromServer();
      CUDPNetworkHandler* udpHand = new CUDPNetworkHandler(((GameInfoPacket*)response)->getData()->ip, std::to_string(((GameInfoPacket*)response)->getData()->port));
      udpHand->initSocket();
      sleep(1);
      udpHand->send(new CAuthUDPPacket(CAUTH_UDP, 0, "bite"));
      IServerPacket<ServerUDPResponse>	*packet;
      while (true)
	{
	  if (udpHand->selectServer(NULL)
	      && (packet = udpHand->receive())
	      && packet->getCommandType() == AUTH_UDP
	      && static_cast<AuthUDPPacket*>(packet)->getData()->success == SUCCESS)
	    break;
	}
      // END
      //
      //

      m = new Manager(udpHand);
      m->loop();
      delete m;
    }
}
