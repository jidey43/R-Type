#ifndef ASERVERPACKET_H_
# define ASERVERPACKET_H_

# include "IServerPacket.hh"

template <typename T>
class AServerPacket : public IServerPacket<T>
{
public:
  AServerPacket(T, size_t);
  virtual ~AServerPacket();

protected:
  T				_command;
  size_t			_size;

public:
  T				getCommandType() const;
  size_t			getPacketSize() const;
  virtual std::string const&	deserialize() = 0;
  virtual bool			checkHeader() = 0;
  virtual void			setRawData(std::string const&) = 0;
};

# include "AServerPacket.tpp"

#endif /* !ASERVERPACKET_H_ */
