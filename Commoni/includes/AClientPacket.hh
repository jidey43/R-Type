#ifndef ACLIENTPACKET_H_
# define ACLIENTPACKET_H_

# include "IClientPacket.hh"

template <typename T>
class AClientPacket : public IClientPacket<T>
{
public:
  AClientPacket(T, uint32_t);
  virtual ~AClientPacket();

protected:
  T				_command;
  uint32_t			_size;

public:
  T				getCommandType() const;
  uint32_t			getDataSize() const;
  virtual std::string const&	deserialize() = 0;
  virtual bool			checkHeader() = 0;
  virtual void			setRawData(std::string const&) = 0;
};

# include "AClientPacket.tpp"

#endif
