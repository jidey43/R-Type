#ifndef AUTHUDPPACKET_H_
# define AUTHUDPPACKET_H_

# include "AServerPacket.hh"

class AuthUDPPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  AuthUDPPacket(ServerUDPResponse, int, std::string const&);
  AuthUDPPacket(ServerUDPHeader*);
  ~AuthUDPPacket();

  std::string const&		deserialize();

 private:
  ServerUDPHeader*		_header;
  AuthUDPData*			_data;
};

#endif
