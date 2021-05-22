#include "HUD.h"

Hud::Hud(View view)
{
  //Cargamos la textura si hay un error se para la ejecucion
  texH = new Textura();
  texI = new Textura();
  texM = new Textura();
  textD = new Textura();
  textQ = new Textura();
  texK = new Textura();

  if (!texH->loadTex("resources/hud/health_bar.png"))
  {
    std::cerr << "Error cargando la imagen health.png";
    exit(0);
  }

  if (!texM->loadTex("resources/hud/health_bar.png"))
  {
    std::cerr << "Error cargando la imagen health.png";
    exit(0);
  }

  if (!texI->loadTex("resources/hud/inventario.png"))
  {
    std::cerr << "Error cargando la imagen inventario.png";
    exit(0);
  }
  if (!textD->loadTex("resources/hud/dialog-box1.png"))
  {
    std::cerr << "Error cargando la imagen textoQ.png";
    exit(0);
  }

  if (!textQ->loadTex("resources/hud/Questview1.png"))
  {
    std::cerr << "Error cargando la imagen textoQ.png";
    exit(0);
  }

  if (!texK->loadTex("resources/objects/Llave.png"))
  {
    std::cerr << "Error cargando la imagen textoQ.png";
    exit(0);
  }

  //Instanciamos los sprites
  healthBar = SpriteSheet(texH, 0, 170, 250, 30);
  healthBar.setSpriteScale(0.75, 0.75);

  healthPoint = SpriteSheet(texH, 30, 170, 10, 35);
  healthPoint.setSpriteScale(0.70, 0.70);

  manaBar = SpriteSheet(texM, 0, 170, 250, 30);
  manaBar.setSpriteScale(0.75, 0.75);

  manaPoint = SpriteSheet(texM, 30, 127, 10, 35);
  manaPoint.setSpriteScale(0.60, 0.75);

  monedita = new Moneda(1, view.getCenter().x + 155, view.getCenter().y - 174);

  slot = SpriteSheet(texI, 10, 23, 93, 80);

  slot.setSpriteScale(0.35, 0.35);

  textDialogo = SpriteSheet(textD, 0, 0, 1890, 1417);
  textDialogo.setSpriteScale(0.11, 0.13);
  textDialogo.setPosition(400, 280);

  textQuest = SpriteSheet(textQ, 0, 0, 1890, 1417);
  textQuest.setSpriteScale(0.11, 0.13);

  key = SpriteSheet(texK, 0, 0, 111, 185);
  key.getSprite().setScale(0.15, 0.15);
}

void Hud::render(sf::RenderWindow &w, Jugador *p, sf::Vector2f view, int cont)
{
  sf::Font f = sf::Font();

  if (!f.loadFromFile("resources/font/alagard.ttf"))
  {
    exit(0);
  }

  sf::Text wAlert = sf::Text();

  std::ostringstream teos;

  texto = sf::Text();
  texto.setFont(f);
  texto.setCharacterSize(10);
  texto.setColor(sf::Color::Black);
  teos << cont;
  texto.setString(teos.str() + "/10");
  texto.setPosition(view.x + 160, view.y - 130);

  wAlert.setFont(f);
  wAlert.setCharacterSize(6);
  wAlert.setColor(sf::Color::Black);
  wAlert.setString("O");

  healthBar.setPosition(view.x - 190, view.y - 150);
  manaBar.setPosition(view.x - 190, view.y - 180);
  textQuest.setPosition(view.x + 58, view.y - 210);

  w.draw(healthBar.getSprite());
  w.draw(manaBar.getSprite());
  monedita->getAnimacion().setPos(sf::Vector2f(view.x + 155, view.y - 174));
  monedita->draw(w);

  if (dialogo == true)
  {
    w.draw(textDialogo.getSprite());
  }

  if (mision == true)
  {
    w.draw(textQuest.getSprite());
    w.draw(texto);
  }

  int puntoS = -220;

  for (size_t i = 0; i < 6; i++)
  {
    //Separacion de los slots
    puntoS = puntoS + 35;
    slot.setPosition(view.x + puntoS, view.y + 140);
    if (i == 5)
    {
      slot.setPosition(view.x + puntoS + 60, view.y + 140);
    }
    w.draw(slot.getSprite());

    if (p->getHasKey() && i == 5)
    {
      key.getSprite().setPosition(view.x + puntoS + 65, view.y + 135);
      w.draw(key.getSprite());
    }

    if (p->getInventory().size() > i)
    {
      if (p->getInventory().at(i)->getTipo() == attack)
      {
        p->getInventory()[i]->getSprite()->setPosition(view.x + puntoS + 20, view.y + 145);
        p->getInventory()[i]->getSprite()->setScale(-0.80f, 0.80f);
        w.draw(*p->getInventory()[i]->getSprite());
        if (p->getInventory().at(i)->getWear())
        {
          wAlert.setPosition(view.x + puntoS + 25, view.y + 150);
          w.draw(wAlert);
        }
      }
      else if (p->getInventory().at(i)->getTipo() == llave)
      {
        p->getInventory()[i]->getSprite()->setPosition(view.x + puntoS + 60, view.y + 145);
        p->getInventory()[i]->getSprite()->setScale(-0.80f, 0.80f);
        w.draw(*p->getInventory()[i]->getSprite());
      }
      else
      {
        //Dibuja la espada en los slots
        p->getInventory().at(i)->getAnimation().setPos(Vector2f(view.x + puntoS + 1.5, view.y + 135.6));
        p->getInventory().at(i)->getAnimation().Draw(w);
        if (p->getInventory().at(i)->getWear())
        {
          wAlert.setPosition(view.x + puntoS + 25, view.y + 150);
          w.draw(wAlert);
        }
      }
    }
  }

  int puntoVida = -160;
  int iteraciones = trunc((p->getHealth() * p->getMaxHealth()) / 100);

  if (p->getHealth() != 5)
  {
    for (int i = 0; i < iteraciones; i++)
    {
      healthPoint.setPosition(view.x + puntoVida, view.y - 179.5);
      //healthPoint.setPosition(puntoVida,20);
      w.draw(healthPoint.getSprite());
      puntoVida = puntoVida + 7;
    }
  }

  int puntoMana = -168;
  int it = trunc((p->getMana() * p->getMaxMana()) / 100) + 1;

  if (p->getMana() != 5)
  {
    for (int i = 0; i < it; i++)
    {
      manaPoint.setPosition(view.x + puntoMana, view.y - 154);

      w.draw(manaPoint.getSprite());
      puntoMana = puntoMana + 7;
    }
  }

  //Dibujamos en texto cuantos puntos de vida tiene el jugador
  sf::Text t = sf::Text();
  t.setFont(f);
  t.setCharacterSize(12);
  std::ostringstream os;
  os << p->getHealth();
  t.setString(os.str());
  //Le establecemos el color
  t.setColor(sf::Color::White);
  // std::cout << "PUNTO MANA: " << puntoMana << endl;
  t.setPosition(view.x - 110, view.y - 173);
  w.draw(t);

  //Dibujamos en texto cuantos puntos de mana tiene el jugador
  sf::Text t2 = sf::Text();
  t2.setFont(f);
  t2.setCharacterSize(12);
  std::ostringstream os2;
  os2 << p->getMana();
  t2.setString(os2.str());
  //Le establecemos el color
  t2.setColor(sf::Color::White);
  t2.setPosition(view.x - 110, view.y - 142);
  w.draw(t2);

  //Dibujamos en texto cuantas monedas tiene el jugador en todo momento
  sf::Text t3 = sf::Text();
  t3.setFont(f);
  t3.setCharacterSize(14);
  std::ostringstream os3;
  os3 << p->getCoins();
  t3.setString(os3.str());
  //Le establecemos el color
  t3.setColor(sf::Color::White);
  t3.setPosition(view.x + 170, view.y - 178);
  //std::cout<<p->getCoins()<<"\n";
  w.draw(t3);
}

void Hud::setDialogo(bool cambio, char tipo)
{
  if (tipo == 'D')
  {
    dialogo = cambio;
    std::cout << "dialogo =" << dialogo << endl;
  }
  if (tipo == 'M')
  {
    mision = cambio;
    std::cout << "mision =" << cambio << endl;
  }
}

void Hud::update(Jugador *j)
{
  if (j != NULL)
  {
    for (unsigned x = 0; x < j->getInventory().size(); x++)
    {
      if (j->getInventory().at(x) != NULL && j->getInventory().at(x)->getTipo() != attack)
      {
        //j->getInventory().at(x)->getAnimation().update();
      }
    }
  }
  monedita->update();
}