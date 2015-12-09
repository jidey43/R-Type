#ifndef FAILPACKET_H_
# define FAILPACKET_H_

# include "AServerPacket.hh"

class FailPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  FailPacket(ServerTCPResponse);
  ~FailPacket();

  std::string const&		deserialize();

 private:
  ServerTCPResponse		_response;
};

#endif /* !FAILPACKET_H_ */
