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
  ClientTCPCommand		command;
  uint32_t			size;
  uint32_t			idx;
} __attribute__ ((packed))	ClientUDPHeader;

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

typedef struct
{
  int		id;
} __attribute__ ((packed)) JoinData;

typedef NewGameData NickData;

template <typename T>
class IClientPacket
{
public:
  virtual ~IClientPacket() {};

public:
  virtual T			getCommandType() const = 0;
  virtual std::string const&	deserialize() = 0;
  virtual void			setRawData(std::string const&) = 0;
  virtual bool			checkHeader() = 0;
  virtual uint32_t		getDataSize() const = 0;
  //virtual std::string&		deserialize() = 0;
};

#endif
