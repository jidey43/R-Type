#ifndef GAMEHANDLER_H_
# define GAMEHANDLER_H_

# include "GameInfo.h"
# include "ClientInfo.h"
# include <vector>

class GameHandler
{
 public:
  GameHandler();
  ~GameHandler();

 private:
  std::vector<GameInfo*>		_gameList;
  int					_maxID;
  std::vector<int>			_ports;

 public:
  GameInfo*				addClientInGame(ClientInfo* client, int id);
  int					startNewGame(std::string const& name);
  std::vector<GameInfo*>&		getGameList();
};

#endif
