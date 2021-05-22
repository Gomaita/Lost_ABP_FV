#pragma once
#include "Animacion.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

class Proyectil
{
private:
    int x, y;
    bool colision;
    bool destruido = false;
    sf::Clock reloj;
    int cooldown;
    float Velocidad;
    sf::Vector2f currVel;
    sf::Clock autodestruccion;
    sf::Texture textura;
    sf::Sprite sprite;
    int movimiento;
    RectangleShape bala;
    RectangleShape hitbox;

    float velocidad;

public:
    Proyectil();
    Proyectil(float dirz, float diry, int movimiento, float vel);
    ~Proyectil();
    void update(float d);
    void draw(sf::RenderWindow &Window);

    void setColisiona(bool valor);
    bool getColisiona();
    //void Colisiona(Enemigo* enemy);

    bool getDestruido();
    void setDestruido(bool);

    //Animacion* animacion_actual;
    Animacion *direccion;

    FloatRect getBounds();
};