#ifndef GAME_H_
# define GAME_H_

# include <string>

class Game
{
public:
	Game(std::string const& name);
	~Game();

private:
	std::string		_name;

public:
	std::string		getName() const;
};

#endif /*!GAME_H_*/
