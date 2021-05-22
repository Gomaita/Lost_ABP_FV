#include "Tienda.h"
#include <iostream>

Tienda::Tienda()
{
  //Reservamos memoria para el vector y generamos los objetos de la tienda
  products.reserve(4);

  //Creamos moneda
  monedita = new Moneda(20, 0, 0);
  genItems();
}

Tienda::~Tienda()
{

  for (std::size_t i = 0; i < products.size(); i++)
  {
    if (products.at(i) != NULL)
    {
      delete products.at(i);
    }
  }
  delete monedita;
}

//Por cada item llamamos a su render
void Tienda::render(sf::RenderWindow &w)
{

  sf::Font f = sf::Font();
  if (!f.loadFromFile("resources/font/alagard.ttf"))
  {
    exit(0);
  }

  for (std::size_t i = 0; i < products.size(); i++)
  {
    if (products.at(i) != NULL)
    {
      //Dibujamos el valor del objeto
      sf::Text t = sf::Text();
      t.setFont(f);
      t.setCharacterSize(16);
      std::ostringstream os;
      os << products[i]->getValue();
      t.setString(os.str());
      //Le establecemos el color
      t.setColor(sf::Color::White);
      t.setPosition(products[i]->getSprite()->getPosition().x + 5, products[i]->getSprite()->getPosition().y + 50);
      w.draw(t);
      //Dibujamos el arma
      products.at(i)->render(w);
      monedita->getAnimacion().setPos(sf::Vector2f(products[i]->getSprite()->getPosition().x + 13, products[i]->getSprite()->getPosition().y + 55));
      monedita->draw(w);
      //w.draw(*coin);
    }
  }
}

void Tienda::genItems()
{
  int num;
  prod p;
  srand(time(NULL));
  num = 3 + rand() % (6 - 3); //generamos un numero aleatorio del 3 al 5 que correspondera con el tipo de objeto
  p = (prod)num;

  products.push_back(new Item(2, p, 300.0, 300.0));

  //con esto evitamos que hayan objetos repetidos en la tienda
  bool repite = true;
  while (repite)
  {
    srand(time(NULL));
    num = 3 + rand() % (6 - 3);
    p = (prod)num;
    if (products[0] != NULL && products[0]->getTipo() == p)
      repite = true;
    else
      repite = false;
  }

  products.push_back(new Item(20, p, 350.0, 300.0));

  products.push_back(new Item(2, heal, 400.0, 300.0));
  products.push_back(new Item(2, mana, 450.0, 300.0));

  //por cada objeto disponible de la tienda lo creamos
}

void Tienda::update(float d)
{
  for (unsigned x = 0; x < products.size(); x++)
  {
    if (products.at(x) != NULL && products.at(x)->getTipo() != attack)
    {
      products.at(x)->getAnimation().update();
    }
  }
  monedita->update();
}

void Tienda::buyItem(Jugador *p)
{
  for (unsigned i = 0; i < products.size(); i++)
  {
    if (p != NULL)
    {
      if (p->getPlayer().getGlobalBounds().intersects(products.at(i)->getHitbox().getGlobalBounds()) && p->getCoins() >= products.at(i)->getValue())
      {
        if (products.at(i) != NULL)
        {
          if (products.at(i)->getTipo() == heal && p->getHealth() != 100)
          { //Coge una pocion de vida y se cura
            p->getHeal(20);
            int co = p->getCoins() - products.at(i)->getValue();
            p->setCoins(co);
            products.erase(products.begin() + i);
          }

          else if (products.at(i)->getTipo() == mana && p->getMana() != 100)
          { //Coge una pocion de mana y se regenera una porcion de la misma
            p->recoverMana(30);
            int co = p->getCoins() - products.at(i)->getValue();
            p->setCoins(co);
            products.erase(products.begin() + i);
          }
          else if (products.at(i)->getTipo() != mana && products.at(i)->getTipo() != heal)
          {
            p->getInventory().push_back(products.at(i));
            //std::cout<<"Dinero : "<<p->getCoins() << endl << "Valor : " << products.at(i)->getValue()<<"\n";
            int co = p->getCoins() - products.at(i)->getValue();
            p->setCoins(co);
            products.erase(products.begin() + i);
          }
          //delete products.at(i);
          //products.at(i)->free();
        }
      }
    }
  }
}