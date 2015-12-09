#ifndef ISERVERPACKET_H_
# define ISERVERPACKET_H_

#include "NetworkDefines.h"

typedef struct
{
  int				magic;
  ServerResponse		command;
  int				size;
} __attribute__ ((packed))	ServerHeader;

typedef struct
{
  int				data;
  int				magic;
} __attribute__ ((packed))	integerData;

typedef struct
{
  int				id;
  int				port;
  int				magic;
} __attribute__ ((packed))	GameInfoData;

typedef struct
{
  int				id;
  char				gameName[256];
  char				players[256];
  int				magic;
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
