# include <iostream>
# include "Server.h"
# include "NetworkHandler.h"
# include "ClientInfo.h"
# include "IThread.h"

int main()
{
	int *a = 0;
	// IThread	thrread();
	Server* server = new Server("127.0.0.1", "4242");
	system("pause");
}
