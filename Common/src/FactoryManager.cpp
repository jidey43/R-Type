#include <iostream>
#include "FactoryManager.hh"
#include "KayberosAlien.hh"
#include "GlamAlien.hh"
#include "YorkAlien.hh"
#include "Xelf16Alien.hh"
#include "ScantAlien.hh"
#include "RiosAlien.hh"
#include "BydoAlien.hh"
#include "DokanAlien.hh"

FactoryManager::FactoryManager(MapController *map, char *levelFileName) : _map(map)
{
  _levelLoader.parseLevel(levelFileName);
  _factories[0] = new AlienFactory<BydoAlien>(ObjectInfo::BYDO);
  _factories[1] = new AlienFactory<GlamAlien>(ObjectInfo::GLAM);
  _factories[2] = new AlienFactory<DokanAlien>(ObjectInfo::DOKAN);
  _nbFactory = 3;
}

FactoryManager::~FactoryManager()
{}

void		FactoryManager::changeLevel(char *level)
{
  _levelLoader.parseLevel(level);
}

void		FactoryManager::initialiseLevel()
{
  unsigned int j = 0;
  unsigned int nb = _levelLoader.getWavesCount();
  Waves waves[nb];

  waves[0] = _levelLoader.getNextWave();
  for (unsigned int i; j != nb; i = i + 1)
    {
      if (i >= _nbFactory)
	{
	  std::cout << "Error: bad type in the waves" << std::endl;
	  break;
	}
      if (waves[j].getType() == _factories[i]->getType())
	{
	  _factories[i]->setWave(waves[j]);
	  j = j + 1;
	  waves[j] = _levelLoader.getNextWave();
	  i = 0;
	}
    }
}

void		FactoryManager::update()
{
  IObject	*obj;
  for (unsigned int i = 0; i != _nbFactory; i = i + 1)
    {
      obj = _factories[i]->getNextEnemy();
      if (obj != NULL)
	{
	  _map->addObject(obj);
	}
    }
}
