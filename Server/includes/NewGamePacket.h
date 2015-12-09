#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "AClientPacket.hh"

class NewGamePacket : public AClientPacket
{
public:
  NewGamePacket();
  ~NewGamePacket();

private:
  ClientCommand		_command;
  NewGameData*		_data;

public:
  void			setRawData(std::string const&);
  NewGameData*		getData() const;
};

#endif
