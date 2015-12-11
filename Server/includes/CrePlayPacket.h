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

 private:
  CrePlayData*			_data;
};


#endif /* !CREPLAYPACKET_H_ */
