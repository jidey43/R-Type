#include "BydoAlien.hh"
#include "BasicAlienProjectile.hh"
#include <stdlib.h>

BydoAlien::BydoAlien(sf::Vector2f speed, sf::Vector2i pos, float coeff) : Alien(speed, pos, coeff)
{}

BydoAlien::~BydoAlien()
{}

void		BydoAlien::update()
{}

IObject		*BydoAlien::BasicShoot()
{ 
	//debug
	
	return NULL;
}
