#include <iostream>
#include "FactoryManager.hh"
#include "Exceptions.hpp"
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
  _factories.push_back(new AlienFactory<BydoAlien>(ObjectInfo::WaveType::BYDO));
  _factories.push_back(new AlienFactory<GlamAlien>(ObjectInfo::WaveType::GLAM));
  _factories.push_back(new AlienFactory<DokanAlien>(ObjectInfo::WaveType::DOKAN));
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
  int j			= 0;
  int nb	        = _levelLoader.getWavesCount();
  std::vector<Waves>	waves(nb);

  waves.push_back(_levelLoader.getNextWave());
  for (int i = 0; j != nb; i = i + 1)
    {
      if (i >= static_cast<int>(_nbFactory))
	{
	  throw Exceptions::FactoryExcept("Error this Factory type is not declare"); 
	  break;
	}
      std::cout << "Wave  = " << waves[j].getType() << "bidule = " << _factories[i]->getType() << std::endl;
      std::cout << j << "  " << _levelLoader.getWavesCount() << std::endl;
      if (waves[j].getType() == _factories[i]->getType())
	{
	  _factories[i]->setWave(waves[j]);
	  j = j + 1;
	  i = 0;
	  if (j < _levelLoader.getWavesCount())
	    waves.push_back(_levelLoader.getNextWave());
	  std::cout << "OKOKOK" << std::endl;
	}
    }
}

std::vector<IObject*>		*FactoryManager::update(const sf::Clock &clock)
{
  std::vector<IObject*>		*list;
  IObject			*obj;

  for (std::vector<IAlienFactory*>::iterator it = _factories.begin(); it != _factories.end(); it++)
    {
      obj = (*it)->getNextEnemy(clock);
      if (obj != NULL)
	{
	  list->push_back(obj);
	}
    }
  return (list);
}
