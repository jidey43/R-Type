#include <iostream>
#include "ViewController.h"
#include "Manager.h"

ViewController *vc;
AssetsController *ac;

int main()
{
	ac = new AssetsController("../../assets/");
	if (ac->loadAssets() == false)
	{
		std::cerr << "assets could not be loaded, aborting . . ." << std::endl;
		return -1;
	}

	vc = new ViewController;

 	Manager m;
	
	m.loop();
}