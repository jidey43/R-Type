#ifndef UNETWORK_H_
# define UNETWORK_H_

# ifdef __linux__

# include "INetwork.hh"

template <class T>
class UNetwork : public INetwork<T>
{
private:
	T*							_socket;
	SOCKET						_listen;
	struct addrinfo*			_addr;
	fd_set*						_readSet;

public:
	UNetwork();
	~UNetwork();

public:
	bool					initClientSocket(std::string const &, std::string const &);
	TransmitStatus			recvData(void *data, int size, SOCKET, ConnectionData *addr);
	TransmitStatus			sendData(void *data, int size, SOCKET, ConnectionData *addr);
	SOCKET					getFd() const;
	void					selectFD(std::vector<SOCKET>& fd, struct timeval *to);
	bool					closeConnection(SOCKET);
};

# include "UNetwork.tpp"

# endif

#endif