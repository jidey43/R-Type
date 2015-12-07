#include "LevelLoader.hh"
#include <iostream>
#include <cstring>

LevelLoader::LevelLoader(char *name)
{
  std::cout << name << std::endl;
  _levelFile.open(name);
  _wawesCount = 0;
}

LevelLoader::~LevelLoader() {}

void		LevelLoader::parseLevel()
{
  if (_levelFile)
    {
      std::string	line;

      while (getline(_levelFile, line, '\n'))
	{
	  _lines.push_back(line);
	  _wawesCount = _wawesCount + 1;
	}
    }
  else
    std::cout << "error" << std::endl;
}

Waves		*LevelLoader::getWaves()
{
  Waves *tpt;
  std::cout << "Level" << std::endl;
  return (tpt);
}

int	main()
{
  char *toto = strdup("../level/Level1.lvl");
  LevelLoader level(toto);
  level.parseLevel();
}
