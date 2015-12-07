#ifndef _LEVEL_LOADER_HH_
# define _LEVEL_LOADER_HH_

# include <fstream>
# include <vector>
# include "Waves.hh"

class	LevelLoader
{
public:
  LevelLoader(char *);
  ~LevelLoader();

  void		setLevelFile(char *);
  void		parseLevel();
  
  Waves		*getWaves();
  
public:
  std::ifstream			_levelFile;
  std::vector<std::string>	_lines;
  int				_wawesCount;
};

#endif

