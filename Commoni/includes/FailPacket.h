#ifndef FAILPACKET_H_
# define FAILPACKET_H_

# include "AServerPacket.hh"

class FailPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  FailPacket(ServerTCPResponse);
  FailPacket(ServerTCPHeader*);
  ~FailPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);

private:
  ServerTCPHeader*		_header;
};

#endif /* !FAILPACKET_H_ */
