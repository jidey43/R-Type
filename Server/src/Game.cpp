#include "Game.h"

Game::Game(std::string const& name)
	: _name(name)
{
}

Game::~Game()
{
}

std::string Game::getName() const
{
	return _name;
}

