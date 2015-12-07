#ifndef NETWORKDEFINES_H_
# define NETWORKDEFINES_H_

# include <string>
# include <iostream>
# define BUFF_LEN 256
# define MAGIC 98

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
    INVALID = 0,
    DESCRIBE_GAME,
    SET_NICK,
    JOIN_GAME,
    CREATE_GAME
  }		ClientCommand;

/*
	Packet : client -> server
*/


#endif
