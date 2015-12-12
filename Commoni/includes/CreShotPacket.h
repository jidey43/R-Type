#ifndef CRESHOTPACKET_H_
# define CRESHOTPACKET_H_

# include "AServerPacket.hh"

class CreShotPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  CreShotPacket(ServerUDPResponse, int, float, float, int);
  CreShotPacket(ServerUDPHeader*);
  ~CreShotPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  CreShotData*			getData() const;

 private:
  CreShotData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !CRESHOTPACKET_H_ */
