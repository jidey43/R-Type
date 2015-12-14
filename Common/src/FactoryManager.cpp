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

FactoryManager::FactoryManager(MapController *map, const char *levelFileName) : _map(map)
{
  _levelLoader.parseLevel(levelFileName);
  _factories.push_back(new AlienFactory<BydoAlien>(ObjectInfo::BYDO));
  _factories.push_back(new AlienFactory<GlamAlien>(ObjectInfo::GLAM));
  _factories.push_back(new AlienFactory<DokanAlien>(ObjectInfo::DOKAN));
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
  int j = 0;
  int nb = _levelLoader.getWavesCount();
  std::vector<Waves> waves(nb);

  waves.push_back(_levelLoader.getNextWave());
  for (int i = 0; j != nb; i = i + 1)
    {
      if (i > (int)_nbFactory)
	{
	  std::cout << "Error: bad type in the waves" << std::endl;
	  break;
	}
      std::cout << waves[j].getType() << " " << _factories[i]->getType() << std::endl;
      if (waves[j].getType() == _factories[i]->getType())
	{
	  std::cout << "put wave" << std::endl;
	  _factories[i]->setWave(waves[j]);
	  j = j + 1;
	  if (j < _levelLoader.getWavesCount())
	    waves.push_back(_levelLoader.getNextWave());
	  i = 0;
	}
      std::cout << "nb " << nb << " j  " << j << " i " <<  i << std::endl;
    }
  std::cout << "---------------------" << std::endl;
}

std::vector<IObject*>		FactoryManager::update(sf::Clock clock)
{
  std::vector<IObject*>		list;
  IObject			*obj;

  for (std::vector<IAlienFactory*>::iterator it = _factories.begin(); it != _factories.end(); it++)
    {
      obj = (*it)->getNextEnemy(clock);
      if (obj != NULL)
	{
	  list.push_back(obj);
	}
    }
  return (list);
}
