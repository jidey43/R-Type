#ifndef JOIN_PACKET_
# define JOIN_PACKET_

# include "AClientPacket.hh"

class JoinPacket : public AClientPacket
{
public:
  JoinPacket();
  ~JoinPacket();

private:
  ClientCommand		_command;
  JoinData*		_data;

public:
  void			setRawData(std::string const&);
  JoinData*		getData() const;
};

#endif
