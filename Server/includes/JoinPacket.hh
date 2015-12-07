#ifndef JOIN_PACKET_
# define JOIN_PACKET_

# include "IClientPacket.hh"

class JoinPacket : public IClientPacket
{
public:
  JoinPacket(std::string const&);
  ~JoinPacket();

private:
  ClientCommand		_command;
  JoinData*		_data;

protected:
  ClientCommand const&	getCommandType() const;
  void			setRawData(std::string const&);
  JoinData*		getData() const;
};

#endif
