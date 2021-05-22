#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Moneda.h"
#include "Item.h"
#include <sstream>
#include "Jugador.h"

class Item;
class Tienda
{

private:
   bool isDrawable = false;
   std::vector<Item *> products;
   sf::Font f;
   Moneda *monedita;

public:
   Tienda();
   ~Tienda();
   void genItems();
   void render(sf::RenderWindow &w);
   bool getDrawable()
   {
      return isDrawable;
   }
   int niv = 2; //Nivel de la tienda que corresponde al numero de objetos que haya en la tienda
   void setDrawable(bool b)
   {
      isDrawable = b;
   }
   std::vector<Item *> &getItems()
   {
      return products;
   };
   //Liberamos memoria

   void buyItem(Jugador *p);
   void update(float);
};