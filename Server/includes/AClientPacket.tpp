template <typename T>
AClientPacket<T>::AClientPacket(T cmd) : _command(cmd)
{
}

template <typename T>
AClientPacket<T>::~AClientPacket()
{
}

template <typename T>
T		AClientPacket<T>::getCommandType() const
{
  return _command;
}

template class	AClientPacket<ClientTCPCommand>;
template class	AClientPacket<ClientUDPCommand>;
