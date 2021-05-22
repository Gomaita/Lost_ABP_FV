#pragma once
#include <string>
#include <iostream>
#include "Enemigo.h"
#include "Animacion.h"
typedef enum prod
{
   arco_normal,
   arco_verde,
   baston,
   espada,
   espada_larga,
   espada_oscura,
   attack,
   llave,
   heal,
   mana
} prod;

class Item
{
private:
   prod tipo;
   bool isEquiped = false;
   bool isWear = false;
   bool cambioAtaque = false;
   bool danyo = false;
   float posX, posY;
   int value = 0;
   int damage = 0;
   Texture *tActual, texturaAtaque;
   RectangleShape itemHitbox;
   Sprite *sprite;
   Animacion keyAnimation, itemAnimation;
   Clock ataque;

public:
   Item(){};
   ~Item();
   Item(int, prod, float, float);

   bool getEquiped()
   {
      return isEquiped;
   }

   bool getWear()
   {
      return isWear;
   }

   void render(sf::RenderWindow &w);

   Sprite *getSprite()
   {
      return sprite;
   }

   int getValue()
   {
      return value;
   }

   void setEquiped(bool t)
   {
      isEquiped = t;
   }

   prod getTipo()
   {
      return tipo;
   }

   void setWear(bool t)
   {
      isWear = t;
   }

   float getValorClock();
   void update();
   void update(Vector2f pos);
   void createKeyAnimation(float, float);
   void createItemAnimation(std::string);
   void startAnimation();
   void endAnimation();
   void setPosition(Vector2f pos);
   void atacar();
   bool cambioAtaqueValue();
   RectangleShape getHitbox();
   Animacion &getAnimation()
   {
      return itemAnimation;
   }

   int getDamageWeapon()
   {
      return damage;
   }

   void setDamageWeapon(int i)
   {
      damage = i;
   }
};