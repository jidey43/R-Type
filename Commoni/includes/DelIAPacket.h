#ifndef DELIAPACKET_H_
# define DELIAPACKET_H_

# include "AServerPacket.hh"

class DelIAPacket : public AServerPacket<ServerUDPResponse>
{
 public:
  DelIAPacket(ServerUDPResponse, int, int);
  DelIAPacket(ServerUDPHeader*);
  ~DelIAPacket();

  std::string const&		deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  DelIAData*			getData() const;

 private:
  DelIAData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !DELIAPACKET_H_ */
