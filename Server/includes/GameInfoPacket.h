#ifndef GAMEINFOPACKET_H_
# define GAMEINFOPACKET_H_

# include "AServerPacket.hh"

class GameInfoPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  GameInfoPacket(ServerTCPResponse, int, int);
  ~GameInfoPacket();

  std::string const&		deserialize();

 private:
  GameInfoData*			_data;
};

#endif /* !GAMEINFOPACKET_H_ */
