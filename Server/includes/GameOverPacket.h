#ifndef GAMEOVERPACKET_H_
# define GAMEOVERPACKET_H_

# include "IServerPacket.hh"

class GameOverPacket : public IServerPacket
{
 public:
  GameOverPacket(ServerResponse, int);
  ~GameOverPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  GameOverData*			_data;
};

#endif /* !GAMEOVERPACKET_H_ */
