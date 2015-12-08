# include "IServerPacket.hh"

class DesGamePacket : public IServerPacket
{
 public:
  DesGamePacket(ServerResponse, int, std::string const&, std::string const&);
  ~DesGamePacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
  DesGameData*			_data;
};
