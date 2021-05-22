#include "Moneda.h"

#include <iostream>

Moneda::Moneda()
{
}

Moneda::Moneda(int v, float px, float py)
{
  value = v;
  posX = px;
  posY = py;

  if (!t.loadFromFile("resources/hud/coin-HUD.png"))
  {
    std::cerr << "Error cargando la imagen coin-Consumable.png";
    exit(0);
  }

  coinAnimation = Animacion("resources/hud/coin_gold.png", 32, 0.1f);
  coinAnimation.colocarFrames(IntRect(0 * 32, 0 * 32, 32, 32), IntRect(7 * 32, 0 * 32, 32, 32));
  coinAnimation.setPos(sf::Vector2f(posX, posY));
}

void Moneda::draw(sf::RenderWindow &w)
{
  coinAnimation.Draw(w);
}

void Moneda::update()
{
  coinAnimation.update();
}
