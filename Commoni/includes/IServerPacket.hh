#ifndef ISERVERPACKET_H_
# define ISERVERPACKET_H_

# include "NetworkDefines.h"
# include "ObjectInfo.hpp"

typedef struct
{
  uint32_t			       magic;
  ServerTCPResponse		 command;
  uint32_t			       size;
} __attribute__ ((packed))	ServerTCPHeader;

typedef struct
{
  uint32_t			magic;
  ServerUDPResponse		command;
  uint32_t			size;
  uint32_t			idx;
} __attribute__ ((packed))	ServerUDPHeader;

typedef struct
{
  uint32_t			data;
  uint32_t			magic;
} __attribute__ ((packed))	integerData;

typedef struct
{
  Bool				success;
  uint32_t			magic;
} __attribute__ ((packed))	AuthTCPData;

typedef struct
{
  char          ip[256];
  uint32_t			port;
  uint32_t			magic;
} __attribute__ ((packed))	GameInfoData;

typedef struct
{
  uint32_t			id;
  char				gameName[256];
  char				players[256];
  uint32_t			magic;
} __attribute__ ((packed))	DesGameData;

typedef struct
{
  Bool				success;
  uint32_t			magic;
}  __attribute__ ((packed))    	AuthUDPData;

typedef struct
{
  int				id;
  float				x;
  float				y;
  uint32_t			magic;
}  __attribute__ ((packed))	CrePlayData;

typedef struct
{

  int				id;
  float				x;
  float				y;
  float				speed;
  uint32_t			magic;
  ObjectInfo::ShotType		type;
}  __attribute__ ((packed))	CreObjData;

int				id;
float				x;
float				y;
float				speed;
uint32_t			magic;
ObjectInfo::ObstacleType		type;
}  __attribute__ ((packed))	CreObstacleData;


typedef struct
{
  int				id;
  float				x;
  float				y;
  uint32_t			magic;
  enum ObjectInfo::WaveType	iatype;
}  __attribute__ ((packed))	   CreIAData;


typedef integerData GameOverData;
typedef integerData GameListData;
typedef integerData DelItemData;
typedef CrePlayData MoveData;

template <typename T>
class IServerPacket
{
public:
  virtual ~IServerPacket() {};

public:
  virtual char*			deserialize() = 0;
  virtual bool			checkHeader() = 0;
  virtual void			setRawData(char *) = 0;
  virtual T			getCommandType() const = 0;
  virtual size_t		getPacketSize() const = 0;
};

#endif
