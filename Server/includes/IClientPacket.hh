#ifndef ICLIENTPACKET_H_
# define ICLIENTPACKET_H_

# include <string.h>
# include "NetworkDefines.h"

typedef struct
{
  uint32_t			magic;
  ClientCommand			command;
  int				size;
} __attribute__ ((packed))	ClientTCPHeader;

typedef struct
{
  uint32_t			magic;
  ClientCommand			id;
  uint32_t			size;
  uint32_t			idx;
} __attribute__ ((packed))	ClientUDPHeader;

typedef struct
{
  char		data[BUFF_LEN];
} __attribute__ ((packed)) stringData;

typedef stringData NickData;
typedef stringData NewGameData;

typedef struct
{
  int		id;
} __attribute__ ((packed)) JoinData;

typedef NewGameData NickData;

class IClientPacket
{
public:
  virtual ~IClientPacket() {};

public:
  virtual ClientCommand		getCommandType() const = 0;
  virtual void			setRawData(std::string const&) = 0;
  virtual bool			checkHeader() = 0;
};

#endif
