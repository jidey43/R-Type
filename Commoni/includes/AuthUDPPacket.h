#ifndef AUTHUDPPACKET_H_
# define AUTHUDPPACKET_H_

# include "AServerPacket.hh"

class AuthUDPPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  AuthUDPPacket(ServerUDPResponse, int, int, std::string const&);
  AuthUDPPacket(ServerUDPHeader*);
  ~AuthUDPPacket();

  std::string const&		deserialize();
  bool				checkHeader();
  void				setRawData(char *);
  AuthUDPData*		getData() const;

 private:
  AuthUDPData*			_data;
  ServerUDPHeader*		_header;
};

#endif
