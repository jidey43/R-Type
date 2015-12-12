#ifndef DELSHOTPACKET_H_
# define DELSHOTPACKET_H_

# include "AServerPacket.hh"

class DelShotPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  DelShotPacket(ServerUDPResponse, int, float, float);
  DelShotPacket(ServerUDPHeader*);
  ~DelShotPacket();

  bool				checkHeader();
  void				setRawData(char *);
  DelShotData*			getData() const;
  char*				deserialize();
 private:
  DelShotData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !DELSHOTPACKET_H_ */
