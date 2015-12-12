#ifndef CREPLAYPACKET_H_
# define CREPLAYPACKET_H_

# include "AServerPacket.hh"

class CrePlayPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  CrePlayPacket(ServerUDPResponse, int, float, float);
  CrePlayPacket(ServerUDPHeader*);
  ~CrePlayPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  CrePlayData*			getData() const;

 private:
  CrePlayData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !CREPLAYPACKET_H_ */
