#ifndef NETWORKDEFINES_H_
# define NETWORKDEFINES_H_

# include <string>
# include <iostream>
# define BUFF_LEN 256
# define MAGIC 0xa3c89a44
# define BASE_PORT 4010
# define MAX_GAME 7
# define MAX_PLAYERS 4

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
typedef struct sockaddr_in ClientDatas;

typedef enum
  {
    AUTH_TCP = 1,
    ADD_GAME,
    JOIN_GAME,
    QUIT
  }		ClientCommand;

typedef enum
{
  AUTH = 1,
  GAME_OVER,
  GAME_INFO,
  START_GAME_LIST,
  DES_GAME,
  END_GAME_LIST,
  FAIL
}		ServerResponse;

typedef enum
  {
    AUTH_UDP = 1
  }		GameServerCommand;

typedef struct
{
  uint32_t			magic;
  GameServerCommand		id;
  uint32_t			size;
  uint32_t			idx;
} __attribute__ ((packed))	HeaderServerUDP;

/*
	Packet : client -> server
*/


#endif
