#pragma once

#include "GraphicalItem.h"
#include "ViewController.hh"
#include "AssetsController.hh"

class                   SplashMessage : public GraphicalItem
{
    public:
        SplashMessage();
        ~SplashMessage();
   
   public:
        sf::Drawable*               getDrawable();
        bool                        update(sf::Clock const&);
        
   private:
        sf::Text                    *_message;
};