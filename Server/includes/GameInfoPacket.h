# include "IServerPacket.h"

class GameInfoPacket : public IServerPacket
{
 public:
  GameInfoPacket(ServerResponse, GameInfoData const&);
  ~GameInfoPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  GameInfoData*			_data;
};
