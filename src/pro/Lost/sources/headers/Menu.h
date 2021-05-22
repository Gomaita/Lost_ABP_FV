#pragma once
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <vector>
#include "MEstados.h"
#include "Juego.h"
#include "Contexto.h"
#include "Opciones.h"
#define width 1024
#define height 720
#define MAX_NUMBER_ITEMS 10

class Menu : public MEstados
{
private:
  int selectedItem;
  static Menu *instance;

  sf::Text titleText;
  std::vector<sf::Text> menu;
  sf::Text *play;
  sf::Text *exit;
  int seleccion = 0;
  sf::Texture *texfondo;
  sf::Sprite *sprfondo;
  sf::Texture *texopciones;
  sf::Sprite *spropciones;
  sf::RenderWindow *window;

  Texture tBackground, tControls, tBox, tButtons, tCredits;
  Sprite sBackground, sControls, sBox, sButtons, sCredits;

  int modo = -1;

  sf::Music track;

  Animacion fondo;

  bool controles = false, credits = false;

public:
  Menu();
  ~Menu();
  void Inicializar();
  static Menu *Instance();
  void pause();
  void event(sf::Event event, sf::RenderWindow &window, float);
  void resume();
  void update(sf::RenderWindow &window, float);
  void draw(sf::RenderWindow &window);
  void loadResources();

protected:
  void cargaRecursos();
};