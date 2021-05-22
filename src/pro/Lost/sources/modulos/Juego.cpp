#include "Juego.h"

Juego *Juego::instance = 0;

// Instanciamos un objeto Juego si no hay uno creado antes, si lo esta,  le devolvemos el ya instanciado
Juego *Juego::Instance(int j, bool confirma)
{

  //Cada vez que comienza una partida hay que igualarlo a cero para que no se repita personaje entre partidas
  if (confirma)
    instance = 0;
  if (instance == 0)
  {
    instance = new Juego(j);
  }
  return instance;
}

Juego::Juego(int jugador)
{
  personaje = jugador;
}

//Inicializamos el mundo
void Juego::Inicializar()
{
  m = Mundo::Instance(personaje);
}

//Capturamos los eventos del juego
void Juego::event(sf::Event event, sf::RenderWindow &window, float d)
{
  m->Event(event, window);
}

void Juego::update(sf::RenderWindow &window, float delta)
{
  m->Update(delta);
}

void Juego::draw(sf::RenderWindow &window)
{
  m->Draw(window);
}