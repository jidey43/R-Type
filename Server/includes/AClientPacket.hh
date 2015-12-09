#ifndef ACLIENTPACKET_H_
# define ACLIENTPACKET_H_

# include "IClientPacket.hh"

class AClientPacket : public IClientPacket
{
public:
  AClientPacket();
  virtual ~AClientPacket();

protected:
  ClientCommand		_command;

public:
  ClientCommand		getCommandType() const;
  bool			setRawHeader(ClientHeader* header);
  bool			setRawHeader(HeaderServerUDP* header);
  virtual void		setRawData(std::string const&) = 0;
};

#endif
