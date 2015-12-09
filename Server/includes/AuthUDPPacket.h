#ifndef AUTHUDPPACKET_H_
# define AUTHUDPPACKET_H_

# include "AServerPacket.hh"

class AuthUDPPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  AuthUDPPacket(ServerUDPResponse, int, std::string const&);
  ~AuthUDPPacket();

  std::string const&		deserialize();

 private:
  AuthUDPData*			_data;
};

#endif
