# include "BonusSpeed.hh"

BonusSpeed::BonusSpeed(sf::Vector2f const& speed,
		       sf::Vector2f const& pos,
		       sf::Vector2i const& size,
		       ObjectInfo::Type type,
		       unsigned int id)
  : ABonus(speed, pos, size, type, id)
{
}

BonusSpeed::~BonusSpeed()
{
}

void		BonusSpeed::actionBonus(Object* player)
{
  static_cast<Player*>(player)->speedUp();
}

bool		BonusSpeed::update(const sf::Clock& clock)
{
  if (_pos.x + _size.x < 0 || _pos.x > MAP_SIZE_X
      || _pos.y + _size.y < 0 || _pos.y > MAP_SIZE_Y)
    _isAlive = false;
  this->_pos.x = this->_pos.x - this->_speed.x;
  return true;
}

bool		BonusSpeed::update(const sf::Clock& clock, std::vector<IObject*>& map)
{
  this->update(clock);
  this->collision(map);
  return _isAlive;
}
