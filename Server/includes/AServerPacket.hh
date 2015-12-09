#ifndef ASERVERPACKET_H_
# define ASERVERPACKET_H_

# include "IServerPacket.hh"

template <typename T>
class AServerPacket : public IServerPacket<T>
{
public:
  AServerPacket(T);
  virtual ~AServerPacket();

protected:
  T				_command;

public:
  T				getCommandType() const;
  virtual std::string const&	deserialize() = 0;
  virtual bool			checkHeader() = 0;
  virtual void			setRawData(std::string const&) = 0;
};

# include "AServerPacket.tpp"

#endif /* !ASERVERPACKET_H_ */
