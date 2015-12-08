# include "IServerPacket.hh"

class GameInfoPacket : public IServerPacket
{
 public:
  GameInfoPacket(ServerResponse, int, int);
  ~GameInfoPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  GameInfoData*			_data;
};
