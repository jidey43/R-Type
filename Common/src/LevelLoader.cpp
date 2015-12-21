#include "Exceptions.hpp"
#include "LevelLoader.hh"
#include "Waves.hh"
#include <iostream>
#include <sstream>
#include <cstring>
#include <deque>

LevelLoader::LevelLoader()
{
  _wavesCount = 0;
  _compare[0] = "bydo";
  _compare[1] = "glam";
  _compare[2] = "dokan";
  _compare[3] = "kayberos";
  _compare[4] = "rios";
  _compare[5] = "shell";
  _compare[6] = "york";
  _compare[7] = "xelf16";
}

LevelLoader::~LevelLoader() {}

bool		LevelLoader::verifFirst(const std::string &line)
{
  for (int i = 0; line[i] != '\0'; i = i + 1)
    if ((line[i] < 'a' && line[i] > 'z') || (line[i] < 'A' && line[i] > 'Z'))
      return false;
  return true;
}

bool		LevelLoader::verifOther(const std::string &line)
{
  for (int i = 0; line[i] != '\0'; i = i + 1)
    if (line[i] < '0' && line[i] > '9')
      return false;
  return true;
}

bool		LevelLoader::verifLine(const std::string &line)
{
  std::deque<std::string>	tmp;
  std::string			t;
  int				i;

  for (i = 0; line[i] != '\0'; i = i + 1)
    {
      if (line[i] != ' ')
	{
	  t.push_back(line[i]);
	}
      if (line[i + 1] == ' ' && line[i] != ' ')
	{
	  std::cout << "on ajoute t : " << t << std::endl;
	  tmp.push_back(t);
	  t.clear();
	}
    }
  if (tmp.size() != 9)
    return (false);
  if (verifFirst(tmp.front()) == false)
    return (false);
  i = tmp.size() - 1;
  while (i >= 0)
    {
      if (verifOther(tmp.front()) == false)
	return (false);
      tmp.pop_front();
      i = i - 1;
    }
  return (true);
}

void		LevelLoader::parseLevel(const char *name)
{
  _levelFile.open(name);
  if (_levelFile.is_open())
    {
      std::string	  line;
      
      while (getline(_levelFile, line, '\n'))
	{
	  std::cout << line << std::endl;
	  if (verifLine(line) == true)
	    {
	      std::cout << "true" << std::endl;
	      _lines.push_back(line);
	      _wavesCount = _wavesCount + 1;
	    }
	  else
	    std::cout << "false" << std::endl;
	}
      _levelFile.close();
    }
  else
    throw Exceptions::FactoryExcept("Level file not found");
}

Waves						LevelLoader::getNextWave()
{
      std::string				str = _lines.front();
      sf::Time					time;
      sf::Time					freq;
      sf::Vector2f				pos;
      sf::Vector2f				speed;
      std::istringstream			buffer;
      std::string				name;
      float					fnb;
      int					inb;
      int					nb;
      float					coeff;
      
      buffer.str (str);
      buffer >> name;
      buffer >> nb;
      buffer >> inb;
      pos.x = inb;
      buffer >> inb;
      pos.y = inb;
      buffer >> fnb;
      speed.x = fnb;
      buffer >> fnb;
      speed.y = fnb;
      buffer >> fnb;
      time = sf::milliseconds(fnb);
      buffer >> fnb;
      freq = sf::milliseconds(fnb);
      buffer >> coeff;

      for (inb = 0; name != _compare[inb]; inb = inb + 1);
      
      ObjectInfo::WaveType			type = (ObjectInfo::WaveType)inb;
      _lines.pop_front();
      Waves	wave(nb, time, freq, pos, speed, coeff, type);
      return (wave);
}

const int		LevelLoader::getWavesCount() const
{
  return _wavesCount;
}
