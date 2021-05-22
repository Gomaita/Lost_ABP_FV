#pragma once
#include "Animacion.h"
#include <SFML/Graphics.hpp>

class Moneda
{
private:
   int value;
   float posX, posY;
   bool isTaken = false; //este valor indica si la moneda ha sido cogida por el player para borrarla cuando toque de la escena
   sf::Texture t;
   sf::Sprite s;
   Animacion coinAnimation;

public:
   Moneda();
   Moneda(int, float, float);
   void draw(sf::RenderWindow &w);
   void update();

   const sf::Sprite &getSprite()
   {
      return s;
   }

   int getValue()
   {
      return value;
   }

   void setTaken(bool t)
   {
      isTaken = t;
   }

   Animacion &getAnimacion()
   {
      return coinAnimation;
   }
};