#ifndef ISERVERPACKET_H_
# define ISERVERPACKET_H_

#include "NetworkDefines.h"

typedef struct
{
  uint32_t			magic;
  ServerResponse		command;
  uint32_t			size;
} __attribute__ ((packed))	ServerHeader;

typedef struct
{
  uint32_t			data;
  uint32_t			magic;
} __attribute__ ((packed))	integerData;

typedef struct
{
  uint32_t			id;
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
