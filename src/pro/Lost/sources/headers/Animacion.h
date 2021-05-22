#pragma once
#include "Sprite.h"
#include <iostream>

using namespace std;
using namespace sf;

class Animacion
{
private:
    sf::Texture texture;
    IntRect primFr;
    IntRect ultFr;
    IntRect miFrame;

    float tiempo = 0.0;
    float velAnim;
    float rotacion = 0;

    int size;

    //Variables para lo del reloj
    float totalTime;
    float frameTime;
    bool pingpong;
    bool endloop;

    enum estado
    {
        None,
        Idle,
        Walk,
        Projectile
    };

    bool animar = true;

    sf::Sprite sprite;

    sf::Clock clock;

public:
    Animacion();
    Animacion(string textura, int tamano, float vel);
    void colocarFrames(IntRect primero, IntRect ultimo);
    void update();
    void update(float, Vector2f);
    void rotateSprite(float rotation);
    void Draw(RenderWindow &window);
    void setTextura(Texture t);
    void setPos(Vector2f);
    void Stop();
    void Play();
    void changeSize(float, float);
};
