#ifndef NETWORKDEFINES_H_
# define NETWORKDEFINES_H_

# include <string>
# include <iostream>
# define BUFF_LEN 256

# ifdef _WIN32
# include <io.h>
# include <winsock2.h>
# include <windows.h>
# include <ws2tcpip.h>
typedef SOCKET SOCKET;

# else
# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
typedef int SOCKET;

# endif
typedef addrinfo ConnectionData;

typedef enum
{
	CPACKET
}		PacketSize;

typedef enum
{
	DESCRIBE_GAME = 0,
	SET_NICK,
	JOIN_GAME,
	CREATE_GAME
}		ClientCommand;

/*
	Packet : client -> server
*/

typedef struct		s_ClientPacket
{
	ClientCommand	command;
	char			name[256];
}					ClientPacket;

#endif
