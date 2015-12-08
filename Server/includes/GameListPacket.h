# include "IServerPacket.h"

class GameListPacket : public IServerPacket
{
 public:
  GameListPacket(ServerResponse, int);
  ~GameListPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  GameListData*			_data;
};
