#ifndef NEXTLVLPACKET_H_
# define NEXTLVLPACKET_H_

# include "AServerPacket.hh"

class NextLvlPacket : public AServerPacket<ServerTCPResponse>
{
 public:
  NextLvlPacket(ServerTCPResponse, int);
  NextLvlPacket(ServerTCPHeader*);
  ~NextLvlPacket();

  char*				deserialize();
  bool				checkHeader();
  void				setRawData(char *);
  NextLvlData*			getData() const;

 private:
  ServerTCPHeader*		_header;
  NextLvlData*			_data;
};

#endif /* !NEXTLVLPACKET_H_ */
