#ifndef CREIAPACKET_H_
# define CREIAPACKET_H_

# include "AServerPacket.hh"

class CreIAPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  CreIAPacket(ServerUDPResponse, int, int, float, float);
  CreIAPacket(ServerUDPHeader*);
  ~CreIAPacket();

  std::string const&		deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  CreIAData*			getData() const;

 private:
  CreIAData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !CREIAPACKET_H_ */
