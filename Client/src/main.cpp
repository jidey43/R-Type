#include <iostream>
#include "ViewController.hh"
#include "Manager.hh"

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

<<<<<<< HEAD
	return 0;
}
=======
	vc = new ViewController;

 	Manager m;
	
	m.loop();
}
>>>>>>> b59878fc2805aa1ec6be79819cebe072d2954a90
