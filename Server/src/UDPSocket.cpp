#include "UDPSocket.hh"

UDPSocket::UDPSocket()
{
}

UDPSocket::~UDPSocket()
{
}

int			UDPSocket::startNetwork(std::string const &ip, std::string const &port, addrinfo hints)
{
  struct addrinfo *addr = NULL;
  int result;
  _port = port;
  hints.ai_flags = AI_PASSIVE;
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_protocol = IPPROTO_UDP;
  hints.ai_addr = INADDR_ANY;
  result = getaddrinfo(ip.c_str(), port.c_str(), &hints, &addr);
  if (result != 0) {
    throw Exceptions::NetworkExcept("GETADDRINFO ERROR", errno);
  }

  if ((_listen = socket(addr->ai_family, addr->ai_socktype,
			addr->ai_protocol)) == -1)
    throw Exceptions::NetworkExcept("SOCKET ERROR", errno);

  if (bind(_listen, addr->ai_addr, (int)addr->ai_addrlen) == SOCKET_ERROR)
    {
      freeaddrinfo(addr);
      throw Exceptions::NetworkExcept("BIND ERROR", errno);
    }
  std::cout << "Listening on port : " + _port + " with socket : " << _listen << std::endl;
  return _listen;
}

TransmitStatus			UDPSocket::sendData(const void *buffer, int size, SOCKET sock, ClientDatas *addr)
{
  int res = sendto(_listen, (void *)buffer, size, 0, (sockaddr *)&addr, sizeof(addr));

  if (res == -1)
    throw Exceptions::NetworkExcept("SEND FAILED", errno);
  return (res == -1 ? ERR : PASSED);
}

TransmitStatus			UDPSocket::rcvData(void* buffer, int size, SOCKET sock, ClientDatas *addr)
{
  socklen_t			addr_len = sizeof(addr);
  int				res;

  res = recvfrom(_listen, (void *)buffer, size, 0, (sockaddr *)&addr, &addr_len);
  return (res == -1 ? ERR : (res == 0 ? DISCONNECTED : PASSED));
}

SOCKET				UDPSocket::acceptClient()
{
  return -1;
}
