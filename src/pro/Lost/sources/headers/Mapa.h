#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Jugador.h"
#include "Enemigo.h"
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
using namespace sf;
using namespace tinyxml2;
using namespace std;

class Mapa
{
private:
    //Variables para el mapa
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *map;
    tinyxml2::XMLElement *img;
    tinyxml2::XMLElement *layer;
    tinyxml2::XMLElement *data;
    int _width, _height, _tileWidth, _tileHeight;
    bool **colisiones; // mapa de colisiones
    bool pasado = false;
    int _numLayers;
    int nivelactual;
    int variante = 0;
    int num = 0; //Nº de capas del tileset
    const char *filename;
    char sala;
    string puntoRespawn;
    int ***_tilemap; //GIDs de los tiles del mapa
    bool rellenaSalas = true;
    sf::Sprite ****_tilemapSprite;
    sf::Sprite *_tilesetSprite;
    Texture *_tilesetTexture;
    std::vector<string> nombre_salida;
    std::vector<int> x_salida;
    std::vector<int> y_salida;
    std::vector<string> nombre_enemigo;
    std::vector<int> x_enemigo;
    std::vector<int> y_enemigo;
    std::vector<Enemigo *> enemigos;

public:
    Mapa(int, int);
    virtual ~Mapa();
    void eliminaEnemigo(int);
    void reset();
    void estructurarmapa();
    void leerMapa(int, int);
    void setAtributos();
    void cargarTexturas();
    void creaMapaSprites();
    sf::Vector2f encontrarLlave();
    void leerDatos();
    void crearArraysES();
    void draw(RenderWindow &, Jugador *);
    sf::Vector2f getViewPosition();
    void mapaColisiones(Jugador *);
    void mapaColisiones(Enemigo *);
    bool checkCollision(sf::FloatRect, sf::FloatRect);
    bool checkCollision(Enemigo, Proyectil);
    bool **getColisiones();
    void setActiveLayer(int layer);
    int _activeLayer;
    int cambiodemapa(Jugador *player);
    void generarnuevomapa(string nuevomapa, Jugador *player);
    void setNivelActual(int);
    string getNombreSala();
    Vector2i puntoInicio(string);
    void setVariante(int);
    void setPosEnemy();
    void compruebaEnemigos(float, float, float);
    std::vector<Enemigo *> getEnemigos();
};
