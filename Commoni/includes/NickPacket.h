#ifndef NICKPACKET_H_
# define NICKPACKET_H_

# include "AClientPacket.hh"

class NickPacket : public AClientPacket<ClientTCPCommand>
{
public:
  NickPacket(ClientTCPCommand, std::string const&);
  NickPacket(ClientTCPHeader*);
  ~NickPacket();

private:
  ClientTCPHeader	*_header;
  NickData*		_data;

public:
  void			setRawData(std::string const&);
  NickData*		getData() const;
  bool			checkHeader();
  std::string const&	deserialize();
};

#endif
