#include "SplashMessage.hh"

SplashMessage::SplashMessage(std::string message)
{
    _message = message;
    _messageDrawable = new sf::Text();
    _messageDrawable->setFont(*(ac->getFont(SPLASH)));
    _messageDrawable->setString(_message);
    _messageDrawable->setCharacterSize(100);
    _messageDrawable->setPosition(sf::Vector2f(0, 0));
    _moveCoeff = 0.01;
    
}

SplashMessage::~SplashMessage()
{
    
}

sf::Drawable*               SplashMessage::getDrawable()
{
    return _messageDrawable;
}

bool                        SplashMessage::update(sf::Clock const&)
{
    if (_moveCoeff >= 1)
        return false;
   _moveCoeff += 0.01;
   _messageDrawable->setPosition(RES_X * _moveCoeff, RES_Y * _moveCoeff);
}



