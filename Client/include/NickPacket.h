#ifndef NICKPACKET_H_
# define NICKPACKET_H_

# include "AClientPacket.hh"

class NickPacket : public AClientPacket<ClientTCPCommand>
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
