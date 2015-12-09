#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "AClientPacket.hh"

class NewGamePacket : public AClientPacket<ClientTCPCommand>
{
public:
  NewGamePacket(ClientTCPHeader*);
  ~NewGamePacket();

private:
  NewGameData*		_data;
  ClientTCPHeader*	_header;

public:
  void			setRawData(std::string const&);
  NewGameData*		getData() const;
  bool			checkHeader();
};

#endif
