#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "AClientPacket.hh"

class NewGamePacket : public AClientPacket<ClientTCPCommand>
{
public:
  NewGamePacket(ClientTCPCommand, std::string const&);
  ~NewGamePacket();

private:
  NewGameData*		_data;
  ClientTCPHeader*	_header;

public:
  void			setRawData(std::string const&);
  NewGameData*		getData() const;
  bool			checkHeader();
  std::string const&	deserialize();
};

#endif
