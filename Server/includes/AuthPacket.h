#ifndef AUTHPACKET_H_
# define AUTH_PACKET_H_

# include "IServerPacket.hh"

class AuthPacket : public IServerPacket
{
 public:
  AuthPacket(ServerResponse, int);
  ~AuthPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  AuthData*			_data;
};

#endif
