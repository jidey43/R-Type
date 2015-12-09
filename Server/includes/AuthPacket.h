#ifndef AUTHPACKET_H_
# define AUTH_PACKET_H_

# include "IServerPacket.hh"

class AuthPacket : public IServerPacket
{
 public:
  AuthPacket(ServerTCPResponse, int);
  ~AuthPacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
  AuthData*			_data;
};

#endif
