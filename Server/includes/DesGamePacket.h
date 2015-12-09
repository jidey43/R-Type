# include "IServerPacket.hh"

class DesGamePacket : public IServerPacket
{
 public:
  DesGamePacket(ServerTCPResponse, int, std::string const&, std::string const&);
  ~DesGamePacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
  DesGameData*			_data;
};
