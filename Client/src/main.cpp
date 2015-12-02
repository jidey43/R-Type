# include <iostream>
# include "Client.h"
# include "NetworkHandler.h"
# include "ViewController.h"
# include "AssetsController.h"

ViewController *vc = new ViewController();
AssetsController *ac = new AssetsController("./assets");

int main()
{
	Client* client = new Client("127.0.0.1", "4342");
	system("pause");
}
