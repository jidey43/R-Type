#include "LevelLoader.hh"
#include "Waves.hh"
#include <cstring>
#include <iostream>

int     main()
{
  char *toto = strdup("level/Level1.lvl");
  LevelLoader level;
  level.parseLevel(toto);
  Waves waves = level.getNextWave();
  std::cout << waves.getCount() << std::endl;
}

