#include "LevelLoader.hh"
#include "Waves.hh"
#include <iostream>
#include <sstream>
#include <cstring>

LevelLoader::LevelLoader(char *name)
{
  std::cout << name << std::endl;
  _levelFile.open(name);
  _wawesCount = 0;
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

void		LevelLoader::parseLevel()
{
  std::cout << "ca buuuug : " << _levelFile.is_open() << std::endl;
  if (_levelFile.is_open())
    {
      
      std::string	  line;

      while (getline(_levelFile, line, '\n'))
	{
	  std::cout << line << std::endl;
	  _lines.push_back(line);
	  _wawesCount = _wawesCount + 1;
	}      
    }
  else
    std::cout << "error" << std::endl;
  _levelFile.close();
}

Waves		*LevelLoader::getNextWave()
{
  std::string				str = _lines.front();
  sf::Time				time;
  sf::Time				freq;
  sf::Vector2i				pos;
  sf::Vector2f				speed;
  std::istringstream                    buffer;
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

  int	i;
  for (i = 0; name != _compare[i];i = i + 1);
  ObjectInfo::WaveType			type = (ObjectInfo::WaveType)i;
   
  _lines.pop_front();
  Waves	*wave = new Waves(nb, time, freq, pos, speed, coeff, type);
  std::cout << "NB ALien   " << wave->getCount() << " Type Alien " << type << " " << name << "pos : " << pos.x << " " << pos.y << "speed :  "  << speed.x << "  " << speed.y << " coeef  :" << wave->getCoeff() << std::endl;

  return (wave);
}
