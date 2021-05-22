#pragma once

#include <string>
#include <iostream>
#include "Mapa.h"
#include "Mundo.h"
#include "MEstados.h"

class Mundo;

class Juego : public MEstados
{
private:
    static Juego *instance;
    Mundo *m;
    int personaje;

public:
    Juego(int);
    void Inicializar();
    static Juego *Instance(int, bool);
    void event(sf::Event event, sf::RenderWindow &window, float delta);
    void update(sf::RenderWindow &window, float);
    void draw(sf::RenderWindow &window);
};