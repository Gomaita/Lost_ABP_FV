#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include "Moneda.h"
#include "Tienda.h"
#include "HUD.h"
#include "Fin.h"
#include "Win.h"
#include "Mapa.h"
#include "Contexto.h"
#include "MEstados.h"
#include <vector>

class Mundo
{
private:
    static Mundo *instance;
    bool cambia = false;
    int aux = 0;
    int dif = 0, lvl = 0;
    float randomrow, randomcol;
    Jugador *j;
    Hud *h;
    Tienda *t;
    //std::vector<Enemigo*> enemies;
    Mapa *map;
    sf::View view;
    Texture tBackground;
    int probLlave = 0;
    Sprite sBackground;
    std::vector<int> mapa1;
    std::vector<bool> pasado;
    sf::Clock pulsarE;
    sf::Vector2f pos;
    sf::Vector2f pos_llave;
    Item *key;

    sf::Clock ataque_enemigo;

    bool cambiomob = false;
    bool esCreada = false;
    bool pulsado = false;
    bool mision = false;
    bool mantener_llave = false;
    int contmobs = 0;
    int enemigosactuales;
    size_t enemigosaux;
    bool entrar = false;

public:
    Mundo(int);
    ~Mundo();
    Mundo(const Mundo &);
    Mundo &operator=(const Mundo &);
    static Mundo *Instance(int);
    int getPosMapa(int);
    void Event(sf::Event event, sf::RenderWindow &window);
    void Update(float);
    void Draw(sf::RenderWindow &window);
    void EndGame();
    void estructurarmapa();
};
