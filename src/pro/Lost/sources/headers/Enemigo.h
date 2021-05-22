#pragma once
#include "Proyectil.h"
class Proyectil;

class Enemigo
{
private:
    int health;
    int x, y; // movimiento
    RectangleShape enemy;
    RectangleShape coli[4];

    int tipo;
    float velocidad;

    bool movi[4];
    bool seMueve = true;
    int dir_4 = 1;

    bool muere = false;
    bool der = false;
    bool izq = true;
    bool abj = true;
    bool arr = true;
    bool onTarget = false;

    bool movido = false;
    int damage;

    enum MOV
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    bool ataca = false;
    sf::Clock cdAttack;
    std::vector<Proyectil *> proyectiles;

public:
    Enemigo();
    Enemigo(int, float, int, int, int, int);
    virtual ~Enemigo();
    void update(float, float, float);
    void getDamage(int d);
    void getHeal(int d);
    void elegirEnemigo(int n);
    void setPosition();
    void movimiento(float d, float posJx, float posJy);
    void changeAnimation(Animacion *newAnimation);
    void draw(sf::RenderWindow &window);
    void setNombre(string);
    void setX(int);
    void setY(int);
    int getPosX();
    int getPosY();
    int getVida();
    int Ataque();
    void changedirection(bool);
    void cambioDireccion(int n);
    void compruebaMov(int, bool);
    bool haMuerto();
    void setMuere(bool);

    RectangleShape getColision(int);
    Animacion *animacion;
    Animacion arriba, abajo, izquierda, derecha;
    RectangleShape &getShape();
    RectangleShape &getcoli(int i);

    std::vector<Proyectil *> getProyectiles();
    void borrarProyectil(int i);
    int getTipo();
};