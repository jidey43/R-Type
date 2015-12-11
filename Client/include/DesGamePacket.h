#ifndef DESGAMEPACKET_H_
# define DESGAMEPACKET_H_

# include "AServerPacket.hh"

class DesGamePacket : public AServerPacket<ServerTCPResponse>
{
 public:
  DesGamePacket(ServerTCPResponse, int, std::string const&, std::string const&);
  DesGamePacket(ServerTCPHeader*);
  ~DesGamePacket();

  std::string const&		deserialize();
  bool				checkHeader();
  void				setRawData(std::string const&);
  DesGameData*			getData() const;

 private:
  DesGameData*			_data;
  ServerTCPHeader*		_header;
};

#endif /* !DESGAMEPACKET_H_ */
