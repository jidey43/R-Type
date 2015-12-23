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
#include "Obstacle.hh"
#include "ShellAlien.hh"

FactoryManager::FactoryManager(MapController *map, const char *levelFileName) : _map(map)
{
  _levelLoader.parseLevel(levelFileName);
  _factories.push_back(new AlienFactory<BydoAlien>(ObjectInfo::WaveType::BYDO));
  _factories.push_back(new AlienFactory<GlamAlien>(ObjectInfo::WaveType::GLAM));
  _factories.push_back(new AlienFactory<DokanAlien>(ObjectInfo::WaveType::DOKAN));
  _factories.push_back(new AlienFactory<KayberosAlien>(ObjectInfo::WaveType::KAYBEROS));
  _factories.push_back(new AlienFactory<RiosAlien>(ObjectInfo::WaveType::RIOS));
  _factories.push_back(new AlienFactory<ScantAlien>(ObjectInfo::WaveType::SCANT));
  _factories.push_back(new AlienFactory<ShellAlien>(ObjectInfo::WaveType::SHELL));
  _factories.push_back(new AlienFactory<YorkAlien>(ObjectInfo::WaveType::YORK));
  _factories.push_back(new AlienFactory<Xelf16Alien>(ObjectInfo::WaveType::XELF16));
  //  _factories.push_back(new AlienFactory<Obstacle>(ObjectInfo::WaveType::OBSTACLE));
  _nbFactory = _factories.size();
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
  std::vector<Waves*>	waves;
  
  waves.push_back(_levelLoader.getNextWave());
  for (int i = 0; j != nb; i = i + 1)
    {
      if (waves[j] == NULL)
	j = j + 1;
      if (i >= static_cast<int>(_nbFactory))
	{
	  throw Exceptions::FactoryExcept("Error this Factory type is not declared");
	  break;
	}
      if (waves[j]->getType() == _factories[i]->getType())
	{
	  _factories[i]->setWave(waves[j]);
	  j = j + 1;
	  i = -1;
	  if (j < nb)
	    {
	      waves.push_back(_levelLoader.getNextWave());
	    }
	}
    }
}

std::vector<IObject*>		*FactoryManager::update(const sf::Clock &clock)
{
  std::vector<IObject*>		*list = new std::vector<IObject*>;
  std::vector<IObject*>		*obj;

  for (std::vector<IAlienFactory*>::iterator it = _factories.begin(); it != _factories.end(); it++)
    {
      obj = (*it)->getNextEnemy(clock);
      for (auto it = obj->begin(); it != obj->end(); it++)
	{
	  if (*it != NULL)
	    {
	      list->push_back(*it);
	    }
	}
      delete obj;
    }
  return (list);
}
