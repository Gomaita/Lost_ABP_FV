#pragma once
#include <vector>
#include "Item.h"
#include "Animacion.h"
#include "Proyectil.h"
using namespace sf;
using namespace std;

class Jugador
{
private:
   int health;
   const int maxHealth = 20;
   const int maxMana = 20;
   int mana;
   int coins;
   int tipoPersonaje;
   Item *Arma;

   float velocidad;
   float deltaTime;

   bool hasKey = false;

   std::vector<Item *> inventory;

   float posX = 0.0, posY = 0.0;
   string lastKeyPressed;
   bool movimiento[4];
   bool seMueve = true;
   bool cambia = false;
   enum col
   {
      UP,
      DOWN,
      LEFT,
      RIGHT
   };
   bool abj = true;
   bool arr, izq, der = false;
   bool ataque = false;

   RectangleShape jugador, ataqueHitbox;
   RectangleShape colision[4];

   sf::Clock cdAttack, colisionaClock;
   bool puedeatacar = true;

   Vector2f player;
   std::vector<Proyectil *> proyectiles;

   Animacion idle;

   //Textura y Sprite para la pantalla
   Texture tPantalla;
   Sprite sPantalla;

public:
   Jugador(int m, int v, float vel, int personaje);
   ~Jugador();
   void getDamage(int d);

   std::vector<Item *> &getInventory()
   {
      return inventory;
   }

   void setInventory(std::vector<Item *> iv)
   {
      inventory = iv;
   }

   void draw(sf::RenderWindow &window);
   void elegirJugador(int num);
   void Movimiento(float d);
   void cambiarAnimacion(Animacion *animacion);
   void update(float);
   void setSeMueve(bool);
   bool colisiona(FloatRect, FloatRect);
   sf::RectangleShape getPlayer();
   RectangleShape getColision(int);
   bool Pulsada();
   bool compruebaAtaque();
   void setCambioSala(float, float);
   void setAtaque(bool);
   void compruebaMov(int, bool);
   void setCambia(bool);
   void setDeltaTime(float);
   float getDeltaTime();
   float getVelocidad();
   void getHeal(int h);
   int getHealth();
   int getMaxHealth();
   void gainCoin(int n);
   void spendCoin(int n);
   void spendMana(int d);
   void recoverMana(int h);
   int getMana();
   int getMaxMana();
   int getCoins();
   float getPosX();
   float getPosY();
   sf::Vector2f getMovimiento();
   void setDano(int);
   void muerte();

   std::vector<Proyectil *> getProyectiles();
   void borrarProyectil(int i);

   Animacion *animacion_actual;
   Animacion arriba, abajo, izquierda, derecha;
   Animacion &getAnimacion()
   {
      return idle;
   }

   void setHasKey(bool b)
   {
      hasKey = b;
   }

   bool getHasKey()
   {
      return hasKey;
   }

   void setCoins(int v)
   {
      coins = v;
   }
};