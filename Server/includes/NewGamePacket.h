#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "IPacket.h"

class NewGamePacket : public IPacket
{
public:
  NewGamePacket(std::string const&);
  ~NewGamePacket();

private:
  ClientCommand		_command;
  NewGameData*		_data;

public:
  ClientCommand const&	getCommandType() const;
  /* bool			setRawHeader(std::string const&); */
  /* HeaderNetwork const&	getHeader() const; */
  bool			setRawData(std::string const&);
  NewGameData*		getData() const;
  /* bool			processCommand(); */
};

#endif
