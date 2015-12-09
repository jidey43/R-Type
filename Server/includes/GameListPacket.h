#ifndef GAMELISTPACKET_H_
# define GAMELISTPACKET_H_

# include "AServerPacket.hh"

class GameListPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  GameListPacket(ServerTCPResponse);
  ~GameListPacket();

  std::string const&		deserialize();
};

#endif /* !GAMELISTPACKET_H_ */
