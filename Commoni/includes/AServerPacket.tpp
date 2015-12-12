template <typename T>
AServerPacket<T>::AServerPacket(T cmd, int size) : _command(cmd), _size(size)
{

}

template <typename T>
AServerPacket<T>::~AServerPacket()
{

}

template <typename T>
T		AServerPacket<T>::getCommandType() const
{
  return _command;
}

template <typename T>
uint32_t	AServerPacket<T>::getDataSize() const
{
  return _size;
}

template class AServerPacket<ServerTCPResponse>;
template class AServerPacket<ServerUDPResponse>;