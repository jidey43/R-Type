#ifndef IPACKET_H_
# define IPACKET_H_

# include "NetworkDefines.h"

typedef struct
{
  ClientCommand	command;
  int		size;
  int		magicNum;
} __attribute__ ((packed)) HeaderNetwork;

class IPacket
{
public:
  virtual ~IPacket() {};

public:
  virtual ClientCommand const&	getCommandType() const = 0;
  virtual bool			setRawHeader(std::string const&) = 0;
  virtual HeaderNetwork const&	getHeader() const = 0;
  virtual bool			setRawData(std::string const&) = 0;
  virtual bool			processCommand() = 0;
};


#endif
