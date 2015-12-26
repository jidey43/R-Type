#ifndef BONUSSPEED_H_
# define BONUSSPEED_H_

# include "ObjectInfo.hpp"
# include "ABonus.hh"
# include "Player.hh"

class BonusSpeed : public ABonus
{
public:
  BonusSpeed(sf::Vector2f const&, sf::Vector2f const&, sf::Vector2i const& , ObjectInfo::Type, unsigned int);
  virtual ~BonusSpeed();
  bool	update(sf::Clock const&, std::vector<IObject*>&);
  bool	update(sf::Clock const&);
  void	actionBonus(Object*);

private:
  BonusSpeed(const BonusSpeed &);
  BonusSpeed &operator=(const BonusSpeed &);
};

#endif /* !BONUSSPEED_H_ */
