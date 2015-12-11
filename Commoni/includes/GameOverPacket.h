#ifndef GAMEOVERPACKET_H_
# define GAMEOVERPACKET_H_

# include "AServerPacket.hh"

class GameOverPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  GameOverPacket(ServerTCPResponse, int);
  GameOverPacket(ServerTCPHeader*);
  ~GameOverPacket();

  std::string const&		deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  GameOverData*			getData() const;

 private:
  ServerTCPHeader*		_header;
  GameOverData*			_data;
};

#endif /* !GAMEOVERPACKET_H_ */
