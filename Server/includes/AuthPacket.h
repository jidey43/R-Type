# include "IServerPacket.h"

class AuthPacket : public IServerPacket
{
 public:
  AuthPacket(ServerResponse, AuthData const&);
  ~AuthPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  AuthData*			_data;
};
