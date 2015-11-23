#ifndef                 CREOBSTACLEPACKET_H_
# define                CREOBSTACLEPACKET_H_

# include               "AServerPacket.hh"
# include               "ObjectInfo.hpp"

class CreObstaclePacket : public AServerPacket<ServerUDPResponse>
{
 public:
  CreObstaclePacket(ServerUDPResponse, int, int, float, float, float, ObjectInfo::ServerObstacleType type);
  CreObstaclePacket(ServerUDPHeader*);
  ~CreObstaclePacket();

  char*				          deserialize();
  bool				          checkHeader();
  void				          setRawData(char *);
  CreObstacleData*			getData() const;

 private:
  CreObstacleData*			_data;
  ServerUDPHeader*		_header;
};


#endif /* !CREOBSTACLEPACKET_H_ */
