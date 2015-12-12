#ifndef GAMEINFOPACKET_H_
# define GAMEINFOPACKET_H_

# include "AServerPacket.hh"

class GameInfoPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  GameInfoPacket(ServerTCPResponse, int, int);
  GameInfoPacket(ServerTCPHeader*);
  ~GameInfoPacket();

 private:
  ServerTCPHeader*		_header;
  GameInfoData*			_data;

 public:
  char*				deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  GameInfoData*			getData() const;
};

#endif /* !GAMEINFOPACKET_H_ */
