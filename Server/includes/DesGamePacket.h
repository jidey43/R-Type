# include "IServerPacket.h"

class DesGamePacket : public IServerPacket
{
 public:
  DesGamePacket(ServerResponse, DesGameData const&);
  ~DesGamePacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  DesGameData*			_data;
};
