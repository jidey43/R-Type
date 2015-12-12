template <typename T>
AServerPacket<T>::AServerPacket(T cmd) : _command(cmd)
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

template class AServerPacket<ServerTCPResponse>;
template class AServerPacket<ServerUDPResponse>;