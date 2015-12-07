#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "IClientPacket.hh"

class NewGamePacket : public IClientPacket
{
public:
  NewGamePacket(std::string const&);
  ~NewGamePacket();

private:
  ClientCommand		_command;
  NewGameData*		_data;

public:
  ClientCommand const&	getCommandType() const;
  void			setRawData(std::string const&);
  NewGameData*		getData() const;
};

#endif
