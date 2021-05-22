#include "Item.h"
#include <iostream>

Item::Item(int v, prod tip, float x, float y)
{
  tActual = new Texture();

  value = v;
  tipo = tip;
  posX = x;
  posY = y;

  itemHitbox.setOutlineThickness(3);
  itemHitbox.setOutlineColor(Color::Yellow);
  itemHitbox.setFillColor(Color::Yellow);
  itemHitbox.setSize(Vector2f(11.f, 15.f));
  //itemHitbox.setOrigin(-8,2.f);
  itemHitbox.setPosition(posX, posY);

  switch (tip)
  {
  case 0:
    if (!tActual->loadFromFile("resources/Armas/arco_normal.png"))
    {
      std::cerr << "Error al cargar la textura: arco_normal.png";
      exit(0);
    }
    //izq = Animacion("resources/Armas/arco_normal.png", 53, 0.07f);
    break;

  case 1:
    if (!tActual->loadFromFile("resources/Armas/arco_verde.png"))
    {
      std::cerr << "Error al cargar la textura: arco_verde.png";
      exit(0);
    }

    //izq = Animacion("resources/Armas/arco_verde.png", 53, 0.07f);
    break;

  case 2:
    if (!tActual->loadFromFile("resources/Armas/baston.png"))
    {
      std::cerr << "Error al cargar la textura: baston.png";
      exit(0);
    }
    //izq = Animacion("resources/Armas/baston.png", 53, 0.07f);
    break;
  case 3:
    createItemAnimation("resources/Armas/espada_tienda.png");

    damage = 30;
    //izq = Animacion("resources/Armas/espada.png", 53, 0.07f);
    break;

  case 4:
    createItemAnimation("resources/Armas/espada2.png");

    damage = 40;

    //izq = Animacion("resources/Armas/espada_larga.png", 53, 0.07f);
    break;
  case 5:
    createItemAnimation("resources/Armas/espada3.png");

    damage = 50;

    //izq = Animacion("resources/Armas/espada_oscura.png", 53, 0.07f);
    break;
  case 6:
    if (!tActual->loadFromFile("resources/Armas/ataque.png"))
    {
      std::cerr << "Error al cargar la textura: ataque";
      exit(0);
    }

    damage = 20;
    break;

  case 7:
    //createKeyAnimation(0.0,0.0);
    break;

  case 8:
    createItemAnimation("resources/objects/poti-vida.png");
    break;

  case 9:
    createItemAnimation("resources/objects/poti-mana.png");
    break;
  }

  sprite = new Sprite(*tActual, sf::IntRect(0, 0, 16, 16));
  sprite->setPosition(x, y);
  sprite->setScale(0.8f, 0.80f);
}

Item::~Item()
{
  delete sprite;
  delete tActual;
}

void Item::createKeyAnimation(float posXx, float posYy)
{
  keyAnimation = Animacion("resources/objects/Llave.png", 111, 0.1f);
  keyAnimation.colocarFrames(IntRect(0 * 111, 0 * 185, 111, 185), IntRect(9 * 111, 0 * 185, 111, 185));
  keyAnimation.changeSize(0.09f, 0.09f);
  keyAnimation.setPos(Vector2f(posXx, posYy));
}

void Item::update(Vector2f pos)
{
  //Hacer un booleano de hacer daño
  itemHitbox.move(pos);
}

void Item::update()
{
  itemAnimation.update();
  keyAnimation.update();
}

void Item::setPosition(Vector2f pos)
{
  itemHitbox.setPosition(pos);
}

void Item::render(sf::RenderWindow &w)
{

  if (tipo == attack && ataque.getElapsedTime().asSeconds() < 1 && cambioAtaque)
  {
    w.draw(*sprite);
  }
  else if (tipo != attack && tipo != llave)
  {
    itemAnimation.Draw(w);
    //w.draw(*sprite);
  }

  if (tipo == llave)
  {
    keyAnimation.Draw(w);
  }
}

void Item::startAnimation()
{
  ataque.restart();
  cambioAtaque = true;
}

void Item::endAnimation()
{
  if (ataque.getElapsedTime().asSeconds() >= 0.2f && cambioAtaque)
  {
    ataque.restart();
    cambioAtaque = false;
  }
}

RectangleShape Item::getHitbox()
{
  return itemHitbox;
}

bool Item::cambioAtaqueValue()
{
  return cambioAtaque;
}

void Item::createItemAnimation(std::string s)
{
  itemAnimation = Animacion(s, 134, 0.1f);
  itemAnimation.colocarFrames(IntRect(0 * 134, 0 * 184, 134, 184), IntRect(9 * 134, 0 * 184, 134, 184));
  itemAnimation.changeSize(0.2f, 0.2f);
  itemAnimation.setPos(Vector2f(posX, posY));
}

float Item::getValorClock()
{
  return ataque.getElapsedTime().asSeconds();
}