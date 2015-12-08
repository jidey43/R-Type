#ifndef CLIENTINFO_H_
# define CLIENTINFO_H_

# include <string>
# include "NetworkDefines.h"
# include "IClientPacket.hh"

class ClientInfo
{
 public:
  ClientInfo(SOCKET socket);
  ClientInfo(SOCKET socket, std::string const& nick);
  ~ClientInfo();

 private:
  bool			_isInGame;
  bool			_disconnected;
  SOCKET		_socket;
  std::string		_nickname;
  IClientPacket*	_packet;

 public:
  bool			isInGame() const;
  void			setPacket(IClientPacket*);
  IClientPacket*	getPacket() const;
  SOCKET		getSocket() const;
  std::string		getNickname() const;
  void			setNickname(std::string const& nick);
  bool			getDisconnected() const;
  void			setDisconnected(bool);
};

#endif
