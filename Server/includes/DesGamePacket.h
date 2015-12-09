#ifndef DESGAMEPACKET_H_
# define DESGAMEPACKET_H_

# include "AServerPacket.hh"

class DesGamePacket : public AServerPacket<ServerTCPResponse>
{
 public:
  DesGamePacket(ServerTCPResponse, int, std::string const&, std::string const&);
  ~DesGamePacket();

  std::string const&		deserialize();

 private:
  DesGameData*			_data;
};

#endif /* !DESGAMEPACKET_H_ */
