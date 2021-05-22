#pragma once
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <vector>
#include "MEstados.h"
#include "Menu.h"
#define width 1024
#define height 720

class Fin : public MEstados
{
private:
  int selectedItem;
  static Fin *instance;

  sf::Text titleText;
  sf::Font f;
  sf::View viewFin;
  sf::Texture tBackground;
  sf::Sprite sBackground;

  sf::Music track;
  bool controles = false;

public:
  Fin();
  ~Fin();
  void Inicializar();
  static Fin *Instance();
  void event(sf::Event event, sf::RenderWindow &window, float);
  void update(sf::RenderWindow &window, float);
  void draw(sf::RenderWindow &window);
};