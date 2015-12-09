# include "IServerPacket.hh"

class GameInfoPacket : public IServerPacket
{
 public:
  GameInfoPacket(ServerTCPResponse, int, int);
  ~GameInfoPacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
  GameInfoData*			_data;
};
