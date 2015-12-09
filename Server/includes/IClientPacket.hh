#ifndef ICLIENTPACKET_H_
# define ICLIENTPACKET_H_

# include <string.h>
# include "NetworkDefines.h"

typedef struct
{
  ClientCommand	command;
  int		size;
  int		magic;
} __attribute__ ((packed)) ClientHeader;

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
  virtual bool			setRawHeader(ClientHeader* header) = 0;
  virtual bool			setRawHeader(HeaderServerUDP* header) = 0;
};

#endif
