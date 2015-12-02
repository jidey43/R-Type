# include "Server.h"
# include "NetworkHandler.h"
# include "ClientInfo.h"
# include "IThread.h"
#include <iostream>


int main()
{
  Server* server = new Server("127.0.0.1", "4342");
  std::cout << "ok" << std::endl;
}
