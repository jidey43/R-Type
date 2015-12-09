#ifndef AUTHPACKET_H_
# define AUTH_PACKET_H_

# include "AServerPacket.hh"

class AuthPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  AuthPacket(ServerTCPResponse, int);
  ~AuthPacket();

  std::string const&		deserialize();

 private:
  AuthData*			_data;
};

#endif
