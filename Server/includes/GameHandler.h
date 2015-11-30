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
	int							_maxPort;

public:
	bool						addClientInGame(ClientInfo* client, std::string const& name);
	bool						startNewGame(std::string const& name);
	std::vector<GameInfo*>&		getGameList();
};

#endif
