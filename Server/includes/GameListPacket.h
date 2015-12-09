#ifndef GAMELISTPACKET_H_
# define GAMELISTPACKET_H_

# include "IServerPacket.hh"

class GameListPacket : public IServerPacket
{
 public:
  GameListPacket(ServerTCPResponse);
  ~GameListPacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
};

#endif /* !GAMELISTPACKET_H_ */
