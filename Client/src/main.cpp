# include <iostream>
# include "Client.h"
# include "NetworkHandler.hh"
# include "ViewController.h"
# include "Manager.hh"
# include "MenuController.hh"
# include "AssetsController.h"

ViewController *vc;
AssetsController *ac;

int main(int ac, char **av)
{
	ac = new AssetsController("../../assets/");
	if (ac->loadAssets() == false)
	{
		std::cerr << "assets could not be loaded, aborting . . ." << std::endl;
		return -1;
	}

	vc = new ViewController;

	Manager *m;
	MenuController menu;

	while (true)
	{
		menu.loop();
		m = new Manager();
		m->loop();
		delete m;
	}
}
