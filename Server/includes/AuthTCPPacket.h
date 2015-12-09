#ifndef AUTHPACKET_H_
# define AUTH_PACKET_H_

# include "AServerPacket.hh"

class AuthTCPPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  AuthTCPPacket(ServerTCPResponse, int);
  ~AuthTCPPacket();

  std::string const&		deserialize();

 private:
  AuthData*			_data;
};

#endif
