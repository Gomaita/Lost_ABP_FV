#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <time.h>
#include "config.h"
#include "Mapa.h"
#include "Menu.h"
#include "Contexto.h"

#define kVel 5
#define UPDATETIME 1000 / 30

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 768), "LOST");
  //window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  //Creamos una ventana
  //std::cout << "Ventana creada"<< std::endl;

  Contexto *game = Contexto::Instance();
  //std::cout << "Contexto creado";
  game->Inicializar();
  game->ChangeState(Menu::Instance());

  sf::Clock clock;
  //std::cout << "Reloj" << std::endl;
  sf::Time timeStartUpdate = clock.getElapsedTime();
  //std::cout << "Empieza el tiempo." << std::endl;

  //Bucle del juego
  while (window.isOpen())
  {
    if ((clock.getElapsedTime().asMilliseconds() - timeStartUpdate.asMilliseconds()) > UPDATETIME)
    {
      while (game->running())
      {
        sf::Event event;
        float delta = clock.restart().asSeconds();
        while (window.pollEvent(event))
        {
          game->event(event, window, delta);
        }

        game->update(window, delta);

        game->draw(window);

        if (!window.isOpen())
          game->quit();
      }
    }
  }

  window.clear();
  window.display();

  return 0;
}