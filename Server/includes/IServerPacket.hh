#ifndef ISERVERPACKET_H_
# define ISERVERPACKET_H_

#include "NetworkDefines.h"

typedef struct
{
  int				data;
} __attribute__ ((packed))	integerData;

typedef struct
{
  int				id;
  int				port;
} __attribute__ ((packed))	GameInfoData;

typedef struct
{
  int				id;
  char				gameName[256];
  char				players[256];
} __attribute__ ((packed))	DesGameData;

typedef integerData GameOverData;
typedef integerData AuthData;
typedef integerData GameListData;

class IServerPacket
{
public:
  virtual ~IServerPacket() {};

public:
  virtual std::string const&	deserialize() = 0;
};

#endif
