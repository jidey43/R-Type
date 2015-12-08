# include <iostream>
# include <signal.h>
# include "Server.h"
# include "IThread.h"

void	broadcast(std::string const& data)
{
  std::vector<ClientInfo*>::const_iterator	it;
  char toSend[BUFF_LEN];

  memset(toSend, 0, BUFF_LEN);
  memcpy(toSend, std::string(data + "\r\n").c_str(), data.size() + 2);
  for (it = _clientList.begin(); it != _clientList.end(); ++it)
    {
      send((*it)->getSocket(), toSend, BUFF_LEN, 0);
    }
}

void		handle_signal(int sig)
{
  (void)sig;
  if (_listen != -1 && _listen)
    {
      broadcast("quit");
      usleep(10000);
      int t = 1;
      std::cout <<  setsockopt(_listen,SOL_SOCKET,SO_REUSEADDR,(char *)&t,sizeof(int)) << std::endl;
      close(_listen);
    }
  exit(EXIT_SUCCESS);
}

int	process_signal()
{
  if (signal(SIGINT, handle_signal) != SIG_ERR
      && signal(SIGQUIT, handle_signal) != SIG_ERR)
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      std::cout << "USAGE : ./server [port]" << std::endl;
      return (1);
    }
  process_signal();
  Server* server = new Server("127.0.0.1", av[1]);
  std::cout << "ok" << std::endl;
}
