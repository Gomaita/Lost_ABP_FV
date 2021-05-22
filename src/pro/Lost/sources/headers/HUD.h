#pragma once
#include "Jugador.h"
#include "Moneda.h"
#include <cmath>
#include <sstream>
#include <iostream>

class Hud
{

private:
   Textura *texH;
   Textura *texC;
   Textura *texI;
   Textura *texM;
   Textura *textD;
   Textura *textQ;
   Textura *texK;
   SpriteSheet healthBar;
   SpriteSheet healthPoint;
   SpriteSheet textDialogo;
   SpriteSheet textQuest;
   SpriteSheet manaBar;
   SpriteSheet manaPoint;
   SpriteSheet slot;
   SpriteSheet key;
   Moneda *monedita;
   sf::Text texto;
   sf::Font f;

   bool dialogo = false;
   int cambio = 0;
   bool mision = false;

public:
   Hud(View);
   void render(sf::RenderWindow &w, Jugador *p, sf::Vector2f view, int cont);
   void setDialogo(bool, char);
   void createCoins();
   void update(Jugador *);
};
