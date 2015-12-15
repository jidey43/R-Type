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

      // INIT DU UDP A LA MAIN
      IServerPacket<ServerTCPResponse> *response;
      tcpHand->sendToServer(new NewGamePacket(ADD_GAME, "Game de l'espace"));
      response = tcpHand->receiveFromServer();
      std::cout << "REPONSE DU SERVEUR " << response->getCommandType() << "\n";
      CUDPNetworkHandler* udpHand = new CUDPNetworkHandler(((GameInfoPacket*)response)->getData()->ip, std::to_string(((GameInfoPacket*)response)->getData()->port));
      udpHand->initSocket();
      sleep(1);
      udpHand->send(new CAuthUDPPacket(CAUTH_UDP, 0, "bite"));
      // END

      m = new Manager(udpHand);
      m->loop();
      delete m;
    }
}
