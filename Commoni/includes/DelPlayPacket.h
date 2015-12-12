#ifndef DELPLAYPACKET_H_
# define DELPLAYPACKET_H_

# include "AServerPacket.hh"

class DelPlayPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  DelPlayPacket(ServerUDPResponse, int);
  DelPlayPacket(ServerUDPHeader*);
  ~DelPlayPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(char *);

 private:
  ServerUDPHeader*		_header;
};


#endif /* !DELPLAYPACKET_H_ */
