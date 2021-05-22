#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class MEstados;
class Contexto
{
private:
  //Pila de estados
  std::vector<MEstados *> mEstados;
  bool cambio;
  static Contexto *pinstance;

public:
  static Contexto *Instance();
  void Inicializar();
  void ChangeState(MEstados *state);
  void event(sf::Event event, sf::RenderWindow &window, float);
  void update(sf::RenderWindow &window, float);
  void draw(sf::RenderWindow &window);
  bool running() { return cambio; }
  void quit() { cambio = false; }
};
