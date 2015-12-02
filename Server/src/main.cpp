# include "Server.h"
# include "NetworkHandler.h"
# include "ClientInfo.h"
# include "IThread.h"
#include <iostream>


int main(int ac, char **av)
{
  Server* server = new Server("127.0.0.1", av[1]);
  std::cout << "ok" << std::endl;
}
