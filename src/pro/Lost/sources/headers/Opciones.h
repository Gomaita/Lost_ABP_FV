#pragma once
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <vector>
#include "MEstados.h"
#include "Animacion.h"
#include "Juego.h"
#define width 1024
#define height 720

class Opciones : public MEstados
{
private:
  static Opciones *instance;
  //Contexto *c;
  sf::Text titleText;
  sf::Font f;
  sf::Texture tButtons;
  sf::Sprite sButtons;
  int modo = -1;
  Animacion playerA, playerB, playerC, playerD;

  sf::Music track;
  bool controles = false;

public:
  Opciones();
  ~Opciones();
  void Inicializar();
  static Opciones *Instance();
  void event(sf::Event event, sf::RenderWindow &window, float);
  void update(sf::RenderWindow &window, float);
  void draw(sf::RenderWindow &window);

protected:
  void cargaRecursos();
};