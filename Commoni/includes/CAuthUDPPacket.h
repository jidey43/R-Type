#ifndef CAUTCHUDPPACKET_H_
# define CAUTCHUDP PACKET_H_

# include "AClientPacket.hh"

class CAuthUDPPacket : public AClientPacket<ClientUDPCommand>
{
 public:
  CAuthUDPPacket(ClientUDPCommand, int, int, std::string const&);
  CAuthUDPPacket(ClientUDPHeader*);
  ~CAuthUDPPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  CAuthUDPData*			getData() const;

 private:
  CAuthUDPData*			_data;
  ClientUDPHeader*		_header;
};

#endif
