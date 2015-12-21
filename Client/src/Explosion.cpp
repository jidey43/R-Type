#include "Explosion.hh"

Explosion::Explosion(sf::Vector2f pos) : GraphicalItem(), _pos(pos)
{
    _sprite->setTexture(*(ac->getExplosion()));
    _sprite->setPosition(sf::Vector2f(_pos.x - (EXPLOSION_X / 2), _pos.y - (EXPLOSION_Y / 2)));
    _sprite->setTextureRect(sf::IntRect(0, 0, 120, 100));
}

Explosion::~Explosion()
{
    
}

bool                Explosion::update(sf::Clock const& clock)
{
    
}