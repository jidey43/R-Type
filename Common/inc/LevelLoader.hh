#ifndef _LEVEL_LOADER_HH_
# define _LEVEL_LOADER_HH_

# include <fstream>
# include <sstream>
# include <deque>
# include <cstddef>
# include <vector>
# include "Waves.hh"

class	LevelLoader
{
public:
  LevelLoader();
  ~LevelLoader();

  void			parseLevel(const char *);
  const Waves		getNextWave();
  const int		getWavesCount() const;

private:
  std::string			 _name;
  std::string			 _oldName;
  std::ifstream			 _levelFile;
  std::deque<std::string>	 _lines;
  std::string			 _compare[8];
  unsigned int		        _wavesCount;
};

#endif

