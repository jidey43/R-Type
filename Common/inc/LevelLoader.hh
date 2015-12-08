#ifndef _LEVEL_LOADER_HH_
# define _LEVEL_LOADER_HH_

# include <fstream>
# include <sstream>
# include <deque>
# include <vector>
# include "Waves.hh"

class	LevelLoader
{
public:
  LevelLoader(char *);
  ~LevelLoader();

  void		setLevelFile(char *);
  void		parseLevel();
  Waves		*getNextWave();

private:
  std::ifstream			 _levelFile;
  std::deque<std::string>	 _lines;
  std::string			 _compare[8];
  int				 _wawesCount;
};

#endif

