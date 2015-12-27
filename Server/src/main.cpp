# include <iostream>
# include <signal.h>
# include "Server.hh"
# include "SNetworkHandler.h"
# include "ClientInfo.h"
# include "IThread.h"

int	main(int ac, char **av)
{
  if (ac != 3)
    {
      std::cout << "USAGE : ./server [ip] [port]" << std::endl;
      return (1);
    }
  Server* server = new Server(av[1], av[2]);
  delete(server);
}
