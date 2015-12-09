#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "AClientPacket.hh"

class NickPacket : public AClientPacket
{
public:
  NickPacket(ClientTCPHeader*);
  ~NickPacket();

private:
  ClientTCPHeader	*_header;
  NickData*		_data;

public:
  void			setRawData(std::string const&);
  NickData*		getData() const;
  bool			checkHeader();
};

#endif
