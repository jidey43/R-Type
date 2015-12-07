#ifndef CLIENTINFO_H_
# define CLIENTINFO_H_

# include <string>
# include "NetworkDefines.h"
# include "IPacket.h"

class ClientInfo
{
public:
	ClientInfo(SOCKET socket);
	ClientInfo(SOCKET socket, std::string const& nick);
	~ClientInfo();

private:
	bool			_isInGame;
	bool			_disconnected;
	SOCKET			_socket;
	std::string		_nickname;
	IPacket*		_packet;

public:
	bool			isInGame() const;
	void			setPacket(IPacket*);
	IPacket*		getPacket() const;
	SOCKET			getSocket() const;
	std::string		getNickname() const;
	bool			getDisconnected() const;
	void			setDisconnected(bool);
};

#endif
