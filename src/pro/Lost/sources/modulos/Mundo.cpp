#include "Mundo.h"
#include <chrono>

Mundo *Mundo::instance = 0;

Mundo *Mundo::Instance(int x)
{
  if (instance == 0)
  {
    instance = new Mundo(x);
    //std::cout << "Instancia mundo";
  }
  return instance;
}

Mundo::Mundo(int pl)
{
  //Inicializaciones para la instancia
  //std::cout << "Mundo iniciado.\n";
  //screenDead = Menu::Instance()

  //Sustituir 1 por pl
  if (pl == 1)
  {
    j = new Jugador(100, 50, 65.5f, pl);
  }
  if (pl == 2)
  {
    j = new Jugador(100, 50, 55.5f, pl);
  }
  if (pl == 3)
  {
    j = new Jugador(50, 100, 65.5f, pl);
  }
  if (pl == 4)
  {
    j = new Jugador(60, 90, 60.5f, pl);
  }

  pos.x = 0.0;
  pos.y = 0.0;

  pos_llave.x = 0.0;
  pos_llave.y = 0.0;

  view.setCenter(j->getPosX(), j->getPosY());
  view.zoom(0.4f);

  t = new Tienda();

  t->setDrawable(true);
  h = new Hud(view);

  // enemies.reserve(5);
  estructurarmapa();
  map = new Mapa(0, 1);
  key = new Item(0, llave, 200, 0.0);
}

Mundo::~Mundo()
{
  //monedas.clear();
  delete t;
  delete h;
  delete j;
  delete map;
  delete key;
  instance = 0;
  int pl = 0;
}

void Mundo::Event(sf::Event event, sf::RenderWindow &window)
{
  switch (event.type)
  {
  case sf::Event::Closed:
    Contexto::Instance()->quit();
    window.close();
    break;

  default:
    break;
  }
}

void Mundo::Update(float d)
{

  //NPC
  if (contmobs >= 10 && mision == true)
  {
    mision = false;
    h->setDialogo(false, 'M');
    j->setCoins(j->getCoins() + 30);
  }

  if (entrar == false)
  {
    enemigosaux = map->getEnemigos().size();
    entrar = true;
  }

  if (mision == true && map->getEnemigos().size() < enemigosaux && enemigosaux != 0 && contmobs < 11)
  {
    contmobs++;
    enemigosaux = map->getEnemigos().size();
    //std::cout << "Enemies LEFT: " << enemigosaux << endl;
    //std::cout << "mision: " << contmobs << endl;
  }

  key->update();

  if (map->getEnemigos().size() == 0)
  {
    entrar = false;
    //cout<<"El nivel EN EL QUE ESTAMOS ES: "<< lvl <<"\n";
    if (lvl != 1099)
    {
      pasado[lvl] = true;
    }

    lvl = map->cambiodemapa(j);
    string nombre = map->getNombreSala();

    if (lvl != aux && lvl != 9999)
    {
      if (lvl == 1099)
      {
        map = new Mapa(0, 1);
        t->setDrawable(true);
      }
      else
      {
        map = new Mapa(lvl, mapa1[lvl - 1]);
        t->setDrawable(false);
      }

      Vector2i pos = map->puntoInicio(nombre);
      j->setCambia(true);

      for (size_t i = 0; i < pasado.size(); i++)
      {
        cout << " La pos " << i << "de pasado es: " << pasado[i] << "\n";
      }
      //Crea enemigo del mapa cuando no se han matado previamente
      if (lvl != 1099)
      {
        if (pasado[lvl] == false)
        {
          map->setPosEnemy();
          enemigosaux = map->getEnemigos().size();
          //std::cout << "AUX ENEMIGOS: " << enemigosaux << endl;
        }
      }

      j->setCambioSala((float)pos.x, (float)pos.y);
      view.setCenter(j->getPosX(), j->getPosY());
    }

    if (lvl == 0)
    {
      if (j->getPosX() > 400 && j->getPosX() < 460 && j->getPosY() > 410 && j->getPosY() < 450)
      {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && pulsado == false)
        {
          h->setDialogo(true, 'D');
          //std::cout << "A ENTRADO EN LA POSICION" << endl;
          pulsarE.restart();
          pulsado = true;
          mision = true;
        }
      }

      //NPC
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && pulsarE.getElapsedTime().asSeconds() >= 1 && pulsado == true)
      {
        h->setDialogo(false, 'D');
        h->setDialogo(true, 'M');
      }
    }
  }

  if (lvl == probLlave && pos_llave.x == 0.0 && pos_llave.y == 0.0)
  {
    pos_llave = map->encontrarLlave();
    //std::cout << "Entra al if 1\n";
    esCreada = true;
  }

  if (j->getHasKey() == false && esCreada == true && mantener_llave == false)
  {
    key->setPosition(Vector2f(pos_llave.x, pos_llave.y));
    key->createKeyAnimation(pos_llave.x, pos_llave.y);
    //std::cout << "Entra al if 2\n";
  }

  ////std::cout << "X: " << pos_llave.x << " " << "Y: " << pos_llave.y << " " << "Soy creada: " << esCreada <<  " Mantengo: " << mantener_llave << endl;

  if (key->getHitbox().getGlobalBounds().intersects(j->getPlayer().getGlobalBounds()))
  {
    esCreada = false;
    mantener_llave = true;
    //std::cout << "Entra en coger la llave\n";
    j->setHasKey(true);
  }

  //----------------------------------------------------------------------------------------
  map->mapaColisiones(j);
  t->update(d);
  if (t->getDrawable())
    t->buyItem(j);

  h->update(j);
  j->update(d);
  view.move(j->getMovimiento() * d);

  for (unsigned i = 0; i < map->getEnemigos().size(); i++)
  {
    // //std::cout<<"Pos: " << i << endl;
    // Colisiones con el personaje principal para ver si le hace pupa
    if (j->colisiona(j->getPlayer().getGlobalBounds(), map->getEnemigos().at(i)->getShape().getGlobalBounds()))
    {
      j->setDano(map->getEnemigos().at(i)->Ataque());
      if (j->getHealth() <= 0)
      {
        this->~Mundo();
        Contexto *c = Contexto::Instance();
        c->ChangeState(Fin::Instance());
        return;
      }
    }

    //map->getEnemigos().at(i)->update(d, j->getPosX(), j->getPosY());
    map->compruebaEnemigos(d, j->getPosX(), j->getPosY());
    map->mapaColisiones(map->getEnemigos().at(i));
    map->compruebaEnemigos(d, j->getPosX(), j->getPosY());

    if (map->getEnemigos().at(i)->getTipo() == 3 || map->getEnemigos().at(i)->getTipo() == 4 || map->getEnemigos().at(i)->getTipo() == 5)
    {
      for (unsigned a = 0; a < map->getEnemigos().at(i)->getProyectiles().size(); a++)
      {
        if (j->getPlayer().getGlobalBounds().intersects(map->getEnemigos().at(i)->getProyectiles().at(a)->getBounds()))
        {
          map->getEnemigos().at(i)->borrarProyectil(a);
          j->getDamage(25);
          if (j->getHealth() <= 0)
          {
            this->~Mundo();
            Contexto *c = Contexto::Instance();
            c->ChangeState(Fin::Instance());
            return;
          }
        }
      }
    }

    for (unsigned a = 0; a < j->getProyectiles().size(); a++)
    {
      if (map->getEnemigos().at(i)->getShape().getGlobalBounds().intersects(j->getProyectiles().at(a)->getBounds()))
      {
        j->borrarProyectil(a);
        map->getEnemigos().at(i)->getDamage(100);

        if (map->getEnemigos().at(i)->getVida() <= 0)
        {
          ////std::cout<<"ENTRO AL IF DE MORIR \n";
          if (map->getEnemigos().at(i) != NULL)
          {
            int t = map->getEnemigos().at(i)->getTipo();
            map->eliminaEnemigo(i);

            if (t == 5)
            {
              this->~Mundo();
              Contexto *c = Contexto::Instance();
              c->ChangeState(Win::Instance());
              return;
            }

            //map->getEnemigos().at(i)->setMuere(true);
          }
        }
      }
    }

    for (unsigned u = 0; u < j->getInventory().size(); u++)
    {
      if (j->getInventory().at(u)->getWear() && j->getInventory().at(0)->cambioAtaqueValue() && map->getEnemigos().at(i)->getShape().getGlobalBounds().intersects(j->getInventory().at(0)->getHitbox().getGlobalBounds()))
      {
        ////std::cout<<"INTERSECTA\n";
        j->recoverMana(10); //Si ataca a un enemigo con la espada recupera 10 puntos de mana
        //En funcion del item seleccionado le pasamos su respectivo punto de ataque
        map->getEnemigos().at(i)->getDamage(j->getInventory().at(u)->getDamageWeapon());
        if (map->getEnemigos().at(i)->getVida() <= 0)
        {
          ////std::cout<<"ENTRO AL IF DE MORIR 2\n";
          int t = map->getEnemigos().at(i)->getTipo();
          map->eliminaEnemigo(i);
          if (t == 5)
          {
            this->~Mundo();
            Contexto *c = Contexto::Instance();
            c->ChangeState(Win::Instance());
            return;
          }
        }
      }
    }
  }
}

void Mundo::Draw(sf::RenderWindow &window)
{
  window.setView(view);
  map->draw(window, j);
  if (t->getDrawable())
  {
    t->render(window);
  }

  if (mantener_llave == false)
  {
    key->render(window);
  }

  //j->draw(window);
  h->render(window, j, view.getCenter(), contmobs);
}

void Mundo::estructurarmapa()
{
  srand(time(NULL));

  for (int contadorsalas = 0; contadorsalas < 11; contadorsalas++)
  {
    mapa1.push_back(rand() % 3 + 1);
    pasado.push_back(false);
  }

  probLlave = rand() % 5;

  switch (probLlave)
  {
  case 0:
    probLlave = 2;
    break;

  case 1:
    probLlave = 3;
    break;

  case 2:
    probLlave = 5;
    break;

  case 3:
    probLlave = 7;
    break;

  case 4:
    probLlave = 8;
    break;

  default:
    break;
  }

  //std::cout << "ESTOY EN LA SALA: " << probLlave << endl;
}

int Mundo::getPosMapa(int n)
{
  return mapa1[n];
}