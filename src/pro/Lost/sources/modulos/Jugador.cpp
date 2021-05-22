#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int v, int m, float vel, int personaje)
{
    mana = m;
    health = v;
    coins = 0;
    inventory.reserve(20);
    posX = 355;
    posY = 450;
    velocidad = vel;
    tipoPersonaje = personaje;

    jugador = RectangleShape(Vector2f(25.f, 35.f));
    //jugador.setOrigin(0, 70/2);
    jugador.setPosition(posX, posY);

    elegirJugador(personaje);

    //Inicializamos movimiento de las colisiones
    for (unsigned i = 0; i < 4; i++)
    {
        movimiento[i] = true;
    }

    //Asignamos la posicion y color del RectangleShape
    for (unsigned i = 0; i < 2; i++)
    {
        colision[i] = RectangleShape(Vector2f(25.f, 5.f));
        colision[i].setFillColor(Color::Yellow);
    }

    for (unsigned i = 2; i < 4; i++)
    {
        colision[i] = RectangleShape(Vector2f(5.f, 22.f));
        colision[i].setFillColor(Color::Yellow);
    }
    //Inicializamos arma
    Arma = new Item(12, attack, posX - 12, posY + 10);
    Arma->setEquiped(true);
    Arma->setWear(true);
    inventory.push_back(Arma);

    colision[UP].setPosition(posX, posY + 12);
    colision[DOWN].setPosition(posX, posY + 35);
    colision[LEFT].setPosition(posX - 2, posY + 16);
    colision[RIGHT].setPosition(posX + 22, posY + 16);
}

Jugador::~Jugador()
{
    delete Arma;
}

void Jugador::elegirJugador(int n)
{
    //std::cout<<"HOLA 1:  "<<n<<"\n";
    if (n == 1)
    {
        //Poner que animacion quiero elegir
        arriba = Animacion("./resources/Personajes/Protagonista_chico.png", 53, 0.07f);
        abajo = Animacion("./resources/Personajes/Protagonista_chico.png", 53, 0.07f);
        izquierda = Animacion("./resources/Personajes/Protagonista_chico.png", 53, 0.07f);
        derecha = Animacion("./resources/Personajes/Protagonista_chico.png", 53, 0.07f);

        //Animacion posicion estatica
        idle = Animacion("./resources/Personajes/Animacion.png", 55, 0.35f);
        idle.colocarFrames(IntRect(0 * 55, 0 * 82, 55, 82), IntRect(2 * 55, 0 * 82, 55, 82));

        coins = 5;
    }
    else if (n == 2)
    {

        arriba = Animacion("./resources/Personajes/Protagonista_chica.png", 53, 0.07f);
        abajo = Animacion("./resources/Personajes/Protagonista_chica.png", 53, 0.07f);
        izquierda = Animacion("./resources/Personajes/Protagonista_chica.png", 53, 0.07f);
        derecha = Animacion("./resources/Personajes/Protagonista_chica.png", 53, 0.07f);
        coins = 2;
    }
    else if (n == 3)
    {

        arriba = Animacion("./resources/Personajes/Protagonista_elfo.png", 53, 0.07f);
        abajo = Animacion("./resources/Personajes/Protagonista_elfo.png", 53, 0.07f);
        izquierda = Animacion("./resources/Personajes/Protagonista_elfo.png", 53, 0.07f);
        derecha = Animacion("./resources/Personajes/Protagonista_elfo.png", 53, 0.07f);

        coins = 4;
    }
    else if (n == 4)
    {
        arriba = Animacion("./resources/Personajes/Protagonista_elfa.png", 53, 0.07f);
        abajo = Animacion("./resources/Personajes/Protagonista_elfa.png", 53, 0.07f);
        izquierda = Animacion("./resources/Personajes/Protagonista_elfa.png", 53, 0.07f);
        derecha = Animacion("./resources/Personajes/Protagonista_elfa.png", 53, 0.07f);
        coins = 1;
    }
    else if (n == 5)
    {
    }
    else
    {
        cout << "Elige una opción correcta" << endl;
    }

    //sf::IntRect(1 * 53, 2 * 78, 53, 78)
    arriba.colocarFrames(IntRect(0 * 53, 0 * 78, 53, 78), IntRect(2 * 53, 0 * 78, 53, 78));
    derecha.colocarFrames(IntRect(0 * 53, 1 * 78, 53, 78), IntRect(2 * 53, 1 * 78, 53, 78));
    abajo.colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));
    izquierda.colocarFrames(IntRect(0 * 53, 3 * 78, 53, 78), IntRect(2 * 53, 3 * 78, 53, 78));

    cambiarAnimacion(&abajo);
}

void Jugador::update(float d)
{

    animacion_actual->update(d, Vector2f(posX, posY));

    this->Movimiento(d);
    ataqueHitbox = Arma->getHitbox();
    Arma->update(sf::Vector2f(posX * d, posY * d));
    Arma->endAnimation();

    if (!proyectiles.empty())
    {
        for (size_t i = 0; i < proyectiles.size(); i++)
        {
            if (!proyectiles.at(i)->getDestruido())
            {
                proyectiles.at(i)->update(d);
            }
            else
            {
                delete proyectiles.at(i);
                proyectiles.erase(proyectiles.begin() + i);
            }
        }
    }

    //esto es para el cooldown del ataque
    if (!puedeatacar && cdAttack.getElapsedTime().asSeconds() > 1)
    {
        puedeatacar = true;
    }

    if (this->getHealth() == 0)
    {
        muerte();
    }
}

void Jugador::borrarProyectil(int i)
{
    delete proyectiles.at(i);
    proyectiles.erase(proyectiles.begin() + i);
}

void Jugador::Movimiento(float d)
{
    posX = 0;
    posY = 0;

    this->setDeltaTime(d);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cambiarAnimacion(&arriba);
        if (movimiento[UP])
        {
            posY -= velocidad;

            arr = true;
            abj = der = izq = false;
        }
        else
        {
            posY = 0;
            movimiento[UP] = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cambiarAnimacion(&abajo);
        if (movimiento[DOWN])
        {
            posY += velocidad;

            abj = true;
            arr = der = izq = false;
        }
        else
        {
            posY = 0;
            movimiento[DOWN] = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        lastKeyPressed = 'A';
        cambiarAnimacion(&izquierda);
        if (movimiento[LEFT])
        {
            posX -= velocidad;

            izq = true;
            abj = der = arr = false;
        }
        else
        {
            posX = 0;
            movimiento[LEFT] = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        lastKeyPressed = 'D';
        cambiarAnimacion(&derecha);
        if (movimiento[RIGHT])
        {
            posX += velocidad;

            der = true;
            abj = izq = arr = false;
        }
        else
        {
            posX = 0;
            movimiento[RIGHT] = true;
        }
    }

    if (tipoPersonaje == 1)
    {
        if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
        {
            cambiarAnimacion(&idle);
        }
    }

    if (Arma->getEquiped())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            Arma->startAnimation();

        if (arr)
        {
            Arma->getSprite()->setScale(-0.80f, 0.80f);
            Arma->setPosition(sf::Vector2f(jugador.getPosition().x + 9, jugador.getPosition().y - 10));
            Arma->getSprite()->setPosition(jugador.getPosition().x + 20, jugador.getPosition().y - 10);
        }
        else if (abj)
        {
            Arma->getSprite()->setScale(-0.80f, 0.80f);
            Arma->setPosition(sf::Vector2f(jugador.getPosition().x + 9, jugador.getPosition().y + 35));
            Arma->getSprite()->setPosition(jugador.getPosition().x + 20, jugador.getPosition().y + 35);
        }
        else if (der)
        {
            Arma->getSprite()->setScale(-0.80f, 0.80f);
            Arma->setPosition(sf::Vector2f(jugador.getPosition().x + 27, jugador.getPosition().y + 10));
            Arma->getSprite()->setPosition(jugador.getPosition().x + 35, jugador.getPosition().y + 10);
        }
        else if (izq)
        {
            Arma->getSprite()->setScale(0.80f, 0.80f);
            Arma->setPosition(sf::Vector2f(jugador.getPosition().x - 12, jugador.getPosition().y + 10));
            Arma->getSprite()->setPosition(jugador.getPosition().x - 12, jugador.getPosition().y + 10);
        }
    }

    /*
    if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::D)){
        animacion_actual->Play();
    }else{
        animacion_actual->Stop();
    }
    */

    if (seMueve)
    {
        jugador.move(posX * d, posY * d);
        Arma->getSprite()->move(posX * d, posY * d);
        colision[UP].move(posX * d, posY * d);
        colision[DOWN].move(posX * d, posY * d);
        colision[LEFT].move(posX * d, posY * d);
        colision[RIGHT].move(posX * d, posY * d);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && puedeatacar)
    {
        cdAttack.restart();
        puedeatacar = false;
        if (mana > 15)
        {
            if (arr)
            {
                Proyectil *proyec = new Proyectil(jugador.getPosition().x, jugador.getPosition().y - 1, 1, 150);
                mana = mana - 15;
                proyectiles.push_back(proyec);
            }
            if (abj)
            {
                Proyectil *proyec = new Proyectil(jugador.getPosition().x, jugador.getPosition().y + 1, 2, 150);
                mana = mana - 15;
                proyectiles.push_back(proyec);
            }
            if (der)
            {
                Proyectil *proyec = new Proyectil(jugador.getPosition().x + 1, jugador.getPosition().y, 3, 150);
                mana = mana - 15;
                proyectiles.push_back(proyec);
            }
            if (izq)
            {
                Proyectil *proyec = new Proyectil(jugador.getPosition().x - 1, jugador.getPosition().y, 4, 150);
                mana = mana - 15;
                proyectiles.push_back(proyec);
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        if (inventory.size() >= 1)
        {
            if (inventory.size() == 1)
                inventory.at(0)->setWear(true);
            else
            {
                for (size_t i = 0; i < inventory.size(); i++)
                {
                    if (i == 0)
                        inventory.at(i)->setWear(true);
                    else
                    {
                        inventory.at(i)->setWear(false);
                    }
                }
            }
            cout << "Seleccionastes el item 1 \n";
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        if (inventory.size() >= 2)
        {
            for (size_t i = 0; i < inventory.size(); i++)
            {
                if (i == 1)
                { //Movemos la hitbox de la espada seleccionada junto al personaje
                    inventory.at(i)->setWear(true);
                }

                else
                {
                    inventory.at(i)->setWear(false);
                }
            }
            cout << "Seleccionastes el item 2 \n";
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        if (inventory.size() >= 3)
        {
            for (size_t i = 0; i < inventory.size(); i++)
            {
                if (i == 2)
                { //Movemos la hitbox de la espada seleccionada junto al personaje
                    inventory.at(i)->setWear(true);
                }

                else
                {
                    inventory.at(i)->setWear(false);
                }
            }
            cout << "Seleccionastes el item 3 \n";
        }
    }
}

void Jugador::cambiarAnimacion(Animacion *animacion)
{
    if (animacion_actual != animacion)
    {
        animacion_actual = animacion;
        animacion_actual->setPos(jugador.getPosition());
    }
}

void Jugador::getDamage(int d)
{
    if (health - d < 0)
        health = 0;
    else
        health = health - d;
}

void Jugador::getHeal(int h)
{
    if (health + h > 100)
        health = 100;
    else
        health = health + h;
}

int Jugador::getHealth()
{
    return health;
}

int Jugador::getMaxHealth()
{
    return maxHealth;
}

int Jugador::getCoins()
{
    return coins;
}

void Jugador::gainCoin(int n)
{
    coins = coins + n;
}

void Jugador::spendCoin(int n)
{
    if (coins - n < 0)
    {
        coins = 0;
    }
    else
        coins = coins - n;
}

void Jugador::spendMana(int d)
{
    if (mana - d < 0)
        mana = 0;

    else
        mana = mana - d;
}

void Jugador::recoverMana(int h)
{
    if (mana + h > 100)
        mana = 100;

    else
        mana = mana + h;
}

sf::RectangleShape Jugador::getPlayer()
{
    return jugador;
}

int Jugador::getMana()
{
    return mana;
}

int Jugador::getMaxMana()
{
    return maxHealth;
}

void Jugador::setSeMueve(bool v)
{
    seMueve = v;
}

bool Jugador::colisiona(FloatRect ene, FloatRect jug)
{
    bool devuelve;

    if (ene.intersects(jug) && colisionaClock.getElapsedTime().asSeconds() >= 1)
    {
        devuelve = true;
        colisionaClock.restart();
    }
}

void Jugador::draw(sf::RenderWindow &window)
{
    animacion_actual->Draw(window);

    // window.draw(jugador);
    for (unsigned int i = 0; i < 4; i++)
    {
        //window.draw(colision[i]);
    }

    if (Arma->getEquiped())
    {
        Arma->render(window);
    }

    if (!proyectiles.empty())
    {
        for (size_t i = 0; i < proyectiles.size(); i++)
        {
            if (proyectiles[i] != NULL)
            {
                proyectiles[i]->draw(window);
            }
        }
    }

    window.draw(sPantalla);
}

sf::RectangleShape Jugador::getColision(int n)
{
    sf::RectangleShape e;

    switch (n)
    {
    case 1:
        e = colision[UP];
        break;
    case 2:
        e = colision[DOWN];
        break;
    case 3:
        e = colision[LEFT];
        break;
    case 4:
        e = colision[RIGHT];
        break;
    default:
        break;
    }

    return e;
}

void Jugador::compruebaMov(int x, bool v)
{
    if (x == 1)
    {
        movimiento[UP] = v;
    }
    else if (x == 2)
    {
        movimiento[DOWN] = v;
    }
    else if (x == 3)
    {
        movimiento[LEFT] = v;
    }
    else if (x == 4)
    {
        movimiento[RIGHT] = v;
    }
}

bool Jugador::Pulsada()
{
    string s = "";

    Event event;

    s += event.key.code;

    if (s != "")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Jugador::setDeltaTime(float x)
{
    this->deltaTime = x;
}

float Jugador::getDeltaTime()
{
    return deltaTime;
}

float Jugador::getVelocidad()
{
    return velocidad;
}

void Jugador::setCambioSala(float x, float y)
{
    if (cambia)
    {
        posX = x;
        posY = y;
        jugador.setPosition(posX, posY);
        animacion_actual->setPos(jugador.getPosition());
        colision[UP].setPosition(posX, posY + 12);
        colision[DOWN].setPosition(posX, posY + 35);
        colision[LEFT].setPosition(posX - 2, posY + 16);
        colision[RIGHT].setPosition(posX + 22, posY + 16);
        cambia = false;
    }
}

void Jugador::setCambia(bool value)
{
    cambia = value;
}

float Jugador::getPosX()
{
    return jugador.getPosition().x;
}

float Jugador::getPosY()
{
    return jugador.getPosition().y;
}

sf::Vector2f Jugador::getMovimiento()
{

    return sf::Vector2f(posX, posY);
}

std::vector<Proyectil *> Jugador::getProyectiles()
{
    return proyectiles;
}

void Jugador::setDano(int dano)
{
    if (dano > health)
    {
        health = 0;
    }
    else
    {
        health = health - dano;
    }
}

void Jugador::muerte()
{
    if (!tPantalla.loadFromFile("resources/menu/muerte.png"))
    {
        //std::cout << "Error en el cargado de la textura muerte.png" << std::endl;
    }
    sPantalla.setTexture(tPantalla);
    sPantalla.setPosition(0, 0);
}