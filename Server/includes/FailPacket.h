#ifndef FAILPACKET_H_
# define FAILPACKET_H_

# include "IServerPacket.hh"

class FailPacket : public IServerPacket
{
 public:
  FailPacket(ServerTCPResponse);
  ~FailPacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
};

#endif /* !FAILPACKET_H_ */
