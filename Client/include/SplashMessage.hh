#pragma once

#include "GraphicalItem.h"
#include "ViewController.hh"
#include "AssetsController.hh"

class                   SplashMessage : public GraphicalItem
{
    public:
        SplashMessage(std::string);
        ~SplashMessage();
   
   public:
        sf::Drawable*               getDrawable();
        bool                        update(sf::Clock const&);
        
   private:
        sf::Text                    *_messageDrawable;
        std::string                 _message;
        float                       _moveCoeff;
};