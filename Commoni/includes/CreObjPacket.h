#ifndef CRESHOTPACKET_H_
# define CRESHOTPACKET_H_

# include "AServerPacket.hh"

class CreObjPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  CreObjPacket(ServerUDPResponse, int, int, float, float, int);
  CreObjPacket(ServerUDPHeader*);
  ~CreObjPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(char *);
  CreObjData*			getData() const;

 private:
  CreObjData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !CRESHOTPACKET_H_ */
