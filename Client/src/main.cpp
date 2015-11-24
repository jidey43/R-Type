#include <iostream>
#include "ViewController.h"
#include "Manager.h"

ViewController *vc;
const std::string assetsPath = "../../assets";

int main()
{
	vc = new ViewController;
	Manager m;
	
	m.loop();
}