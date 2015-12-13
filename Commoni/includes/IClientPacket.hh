#ifndef ICLIENTPACKET_H_
# define ICLIENTPACKET_H_

# include <string.h>
# include "NetworkDefines.h"

typedef struct
{
  uint32_t			magic;
  ClientTCPCommand		command;
  int				size;
} __attribute__ ((packed))	ClientTCPHeader;

typedef struct
{
  uint32_t			magic;
  ClientUDPCommand		command;
  uint32_t			size;
  uint32_t			idx;
} __attribute__ ((packed))	ClientUDPHeader;

typedef struct
{
  int		id;
} __attribute__ ((packed))	JoinData;

typedef struct
{
  char				data[BUFF_LEN];
  uint32_t			magic;
} __attribute__ ((packed))	stringData;

typedef struct
{
  Direction			dir;
  uint32_t			magic;
}				SendMoveData;

typedef struct
{
  float				x;
  float				y;
  uint32_t			magic;
}				FireData;

typedef stringData NickData;
typedef stringData NewGameData;
typedef stringData CAuthUDPData;

template <typename T>
class IClientPacket
{
public:
  virtual ~IClientPacket() {};

public:
  virtual T			getCommandType() const = 0;
  virtual char*			deserialize() = 0;
  virtual void			setRawData(char *) = 0;
  virtual bool			checkHeader() = 0;
  virtual size_t		getPacketSize() const = 0;
};

#endif
