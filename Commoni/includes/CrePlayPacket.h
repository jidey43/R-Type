#ifndef CREPLAYPACKET_H_
# define CREPLAYPACKET_H_

# include "AServerPacket.hh"

class CrePlayPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  CrePlayPacket(ServerUDPResponse, float, float);
  CrePlayPacket(ServerUDPHeader*);
  ~CrePlayPacket();

  std::string const&		deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  CrePlayData*			getData() const;

 private:
  ServerUDPHeader*		_header;
  CrePlayData*			_data;
};


#endif /* !CREPLAYPACKET_H_ */
