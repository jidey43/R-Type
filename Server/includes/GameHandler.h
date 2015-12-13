#ifndef GAMEHANDLER_H_
# define GAMEHANDLER_H_

# include "GameInfo.h"
# include "ClientInfo.h"
# include <vector>

class GameHandler
{
 public:
  GameHandler(std::string const& ip);
  ~GameHandler();

 private:
  std::vector<GameInfo*>		_gameList;
  int					_maxID;
  std::string				_ip;
  std::vector<int>			_ports;

 public:
  GameInfo*				addClientInGame(ClientInfo* client, int id);
  int					startNewGame(std::string const& name);
  std::vector<GameInfo*>&		getGameList();
  void					closeClient(std::vector<GameInfo*>::iterator& it, GameInfo* game);
};

#endif
