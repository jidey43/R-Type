#ifndef GAMELISTPACKET_H_
# define GAMELISTPACKET_H_

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

#endif /* !GAMELISTPACKET_H_ */
