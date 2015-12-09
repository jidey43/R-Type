#ifndef ACLIENTPACKET_H_
# define ACLIENTPACKET_H_

# include "IClientPacket.hh"

class AClientPacket : public IClientPacket
{
public:
  AClientPacket(ClientTCPCommand);
  virtual ~AClientPacket();

protected:
  ClientTCPCommand		_command;

public:
  ClientTCPCommand		getCommandType() const;
  virtual bool		checkHeader() = 0;
  virtual void		setRawData(std::string const&) = 0;
};

#endif
