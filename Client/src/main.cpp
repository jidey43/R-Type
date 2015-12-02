# include "Client.h"
# include "NetworkHandler.h"
#include <iostream>
#include <Windows.h>

int main()
{
	Client* client = new Client("127.0.0.1", "4342");
	system("pause");
}
