#ifndef FAILPACKET_H_
# define FAILPACKET_H_

# include "IServerPacket.hh"

class FailPacket : public IServerPacket
{
 public:
  FailPacket(ServerResponse);
  ~FailPacket();

  std::string const&		deserialize();

 private:
  ServerResponse		_response;
};

#endif /* !FAILPACKET_H_ */
