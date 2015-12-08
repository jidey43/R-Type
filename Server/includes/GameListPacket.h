# include "IServerPacket.hh"

class GameListPacket : public IServerPacket
{
 public:
  GameListPacket(ServerResponse);
  ~GameListPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
};
