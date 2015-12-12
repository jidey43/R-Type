#ifndef AUTHTCPPACKET_H_
# define AUTHTCPPACKET_H_

# include "AServerPacket.hh"

class AuthTCPPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  AuthTCPPacket(ServerTCPResponse, Bool);
  AuthTCPPacket(ServerTCPHeader*);
  ~AuthTCPPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  AuthTCPData*			getData() const;

 private:
  AuthTCPData*			_data;
  ServerTCPHeader*		_header;
};

#endif
