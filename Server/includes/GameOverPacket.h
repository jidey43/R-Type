#ifndef GAMEOVERPACKET_H_
# define GAMEOVERPACKET_H_

# include "IServerPacket.hh"

class GameOverPacket : public IServerPacket
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
