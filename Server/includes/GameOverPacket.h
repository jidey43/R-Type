#ifndef GAMEOVERPACKET_H_
# define GAMEOVERPACKET_H_

# include "AServerPacket.hh"

class GameOverPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  GameOverPacket(ServerTCPResponse, int);
  ~GameOverPacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
  GameOverData*			_data;
};

#endif /* !GAMEOVERPACKET_H_ */
