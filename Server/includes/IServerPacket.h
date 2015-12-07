#include "NetworkDefines.h"
#include "IPacket.h"

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
} __attribute__ ((packed))	GameInfoData;

typedef integerData GameOverData;


class IServerPacket
{
public:
  virtual ~IServerPacket() {};

public:
  virtual std::string const&	deserialize() const = 0;
};
