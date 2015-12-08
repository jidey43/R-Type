#include "LevelLoader.hh"
#include "Waves.hh"
#include <cstring>

int     main()
{
  char *toto = strdup("../../Server/level/Level1.lvl");
  LevelLoader level(toto);
  Waves *waves;
  level.parseLevel();
  waves = level.getNextWave();
}

