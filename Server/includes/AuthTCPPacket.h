#ifndef AUTHTCPPACKET_H_
# define AUTHTCPPACKET_H_

# include "AServerPacket.hh"

class AuthTCPPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  AuthTCPPacket(ServerTCPResponse, int);
  ~AuthTCPPacket();

  std::string const&		deserialize();

 private:
  AuthTCPData*			_data;
};

#endif
