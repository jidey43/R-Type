#ifndef NEWGAMEPACKET_H_
# define NEWGAMEPACKET_H_

# include "AClientPacket.hh"

class NickPacket : public AClientPacket
{
public:
  NickPacket();
  ~NickPacket();

private:
  ClientCommand		_command;
  NickData*		_data;

public:
  void			setRawData(std::string const&);
  NickData*		getData() const;
};

#endif
