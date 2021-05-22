#include "Enemigo.h"

Enemigo::Enemigo()
{
    //constructor por defecto
}

Enemigo::Enemigo(int vida, float vel, int enemigo, int posX, int posY, int dano)
{

    tipo = enemigo;
    health = vida;
    x = posX;
    y = posY;

    // esto hay que modificarlo pasandolo por parametro
    damage = dano;

    if (tipo == 5)
    {
        enemy = RectangleShape(Vector2f(60.f, 90.f));
        enemy.setPosition(x, y);
        elegirEnemigo(tipo);
        //animacion->setPos(sf::Vector2f(x-2000, y-1000));
        velocidad = vel;
    }
    else
    {
        enemy = RectangleShape(Vector2f(25.f, 35.f));
        enemy.setPosition(x, y);
        elegirEnemigo(tipo);
        velocidad = vel;
    }

    //Inicializamos movimiento de las colisiones
    for (unsigned i = 0; i < 4; i++)
    {
        movi[i] = true;
    }

    //Asignamos la posicion y color del RectangleShape
    for (unsigned i = 0; i < 2; i++)
    {
        coli[i] = RectangleShape(Vector2f(25.f, 5.f));
        coli[i].setFillColor(Color::Yellow);
    }

    for (unsigned i = 2; i < 4; i++)
    {
        coli[i] = RectangleShape(Vector2f(5.f, 22.f));
        coli[i].setFillColor(Color::Yellow);
    }

    coli[UP].setPosition(x, y + 12);
    coli[DOWN].setPosition(x, y + 35);
    coli[LEFT].setPosition(x - 2, y + 16);
    coli[RIGHT].setPosition(x + 22, y + 16);
}

Enemigo::~Enemigo()
{
    delete animacion;
}

void Enemigo::elegirEnemigo(int n)
{

    if (n == 1)
    {
        //up = Animacion("./resources/Personajes/Enemigo.png");
        arriba = Animacion("./resources/Personajes/Enemigo.png", 53, 0.1f);
        abajo = Animacion("./resources/Personajes/Enemigo.png", 53, 0.1f);
        izquierda = Animacion("./resources/Personajes/Enemigo.png", 53, 0.1f);
        derecha = Animacion("./resources/Personajes/Enemigo.png", 53, 0.1f);
    }
    if (n == 2)
    {
        arriba = Animacion("./resources/Personajes/Enemigo2.png", 53, 0.1f);
        abajo = Animacion("./resources/Personajes/Enemigo2.png", 53, 0.1f);
        izquierda = Animacion("./resources/Personajes/Enemigo2.png", 53, 0.1f);
        derecha = Animacion("./resources/Personajes/Enemigo2.png", 53, 0.1f);
    }
    if (n == 3)
    {
        arriba = Animacion("./resources/Personajes/Enemigo3.png", 53, 0.1f);
        abajo = Animacion("./resources/Personajes/Enemigo3.png", 53, 0.1f);
        izquierda = Animacion("./resources/Personajes/Enemigo3.png", 53, 0.1f);
        derecha = Animacion("./resources/Personajes/Enemigo3.png", 53, 0.1f);
    }
    if (n == 4)
    {
        arriba = Animacion("./resources/Personajes/Bruja.png", 53, 0.1f);
        abajo = Animacion("./resources/Personajes/Bruja.png", 53, 0.1f);
        izquierda = Animacion("./resources/Personajes/Bruja.png", 53, 0.1f);
        derecha = Animacion("./resources/Personajes/Bruja.png", 53, 0.1f);
    }
    if (n == 5)
    {
        arriba = Animacion("./resources/Personajes/Boss.png", 53, 0.1f);
        abajo = Animacion("./resources/Personajes/Boss.png", 53, 0.1f);
        izquierda = Animacion("./resources/Personajes/Boss.png", 53, 0.1f);
        derecha = Animacion("./resources/Personajes/Boss.png", 53, 0.1f);
    }

    arriba.colocarFrames(IntRect(0 * 53, 0 * 78, 53, 78), IntRect(2 * 53, 0 * 78, 53, 78));
    derecha.colocarFrames(IntRect(0 * 53, 1 * 78, 53, 78), IntRect(2 * 53, 1 * 78, 53, 78));
    abajo.colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));
    izquierda.colocarFrames(IntRect(0 * 53, 3 * 78, 53, 78), IntRect(2 * 53, 3 * 78, 53, 78));

    changeAnimation(&abajo);
}

bool Enemigo::haMuerto()
{
    return muere;
}

void Enemigo::setMuere(bool value)
{
    muere = value;
}

void Enemigo::update(float d, float posJx, float posJy)
{
    animacion->update(d, Vector2f(x, y));

    if (!ataca && cdAttack.getElapsedTime().asSeconds() > 1 && tipo == 3 || !ataca && cdAttack.getElapsedTime().asSeconds() > 0.2 && tipo == 4 || !ataca && cdAttack.getElapsedTime().asSeconds() > 0.5 && tipo == 5)
    {
        ataca = true;
    }

    this->movimiento(d, posJx, posJy);

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

    if (health <= 0)
    {
        muere = true;
    }
}

void Enemigo::getDamage(int d)
{
    if (health - d < 0)
    {
        health = 0;
    }
    else
    {
        health = health - d;
    }
}

void Enemigo::getHeal(int h)
{
    if (health + h > 100)
    {
        health = 100;
    }
    else
    {
        health = health + h;
    }
}

void Enemigo::setPosition()
{
    enemy.setPosition(x, y);
}

//Para que se mueva en x direccion
void Enemigo::changeAnimation(Animacion *newAnimation)
{
    if (newAnimation != animacion)
    {
        animacion = newAnimation;
        if (tipo == 5)
        {

            animacion->setPos(Vector2f(enemy.getPosition().x - 17, enemy.getPosition().y - 15));
        }
        else
        {

            animacion->setPos(enemy.getPosition());
        }
    }
}

void Enemigo::draw(sf::RenderWindow &window)
{
    if (tipo == 5)
    {
        animacion->changeSize(1.5f, 1.5f);
        //  window.draw(enemy);
    }

    animacion->Draw(window);
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
}

void Enemigo::movimiento(float d, float posJx, float posJy)
{

    float distaX = (float)posJx - enemy.getPosition().x;
    float distaY = (float)posJy - enemy.getPosition().y;

    if (abs(distaX) < 100 && abs(distaY) < 100)
    {
        onTarget = true;
    }
    else
    {
        onTarget = false;
    }

    x = 0;
    y = 0;
    if (tipo == 1)
    {
        if (onTarget)
        {
            if (movi[RIGHT] && distaX >= 0)
            {
                changeAnimation(&derecha);
                x += velocidad;
                //cambioDireccion()
            }

            if (movi[LEFT] && distaX < 0)
            {
                changeAnimation(&izquierda);
                x -= velocidad;
            }
            else
            {
                movi[LEFT] = true;
            }

            if (movi[DOWN] && distaY >= 0)
            {
                changeAnimation(&abajo);
                y += velocidad;
            }
            else
            {
                movi[DOWN] = true;
            }

            if (movi[UP] && distaY < 0)
            {
                changeAnimation(&arriba);
                y -= velocidad;
            }
            else
            {
                movi[UP] = true;
            }
        }
        else if (seMueve)
        {
            if (der == false)
            {
                if (movi[RIGHT])
                {
                    changeAnimation(&derecha);
                    //std::cout << "ME MUEVO DERECHA DERECHA" << endl;
                    x += velocidad;
                    y = 0;
                    arr = izq = abj = true;
                }
                else
                {
                    // std::cout << "ME HE CHOCADO" << endl;
                    int num = rand() % 4 + 1;
                    cambioDireccion(num);
                }
            }

            if (izq == false)
            {
                if (movi[LEFT])
                {
                    changeAnimation(&izquierda);
                    //std::cout << "ME MUEVO IZQUIERDA" << endl;
                    x -= velocidad;
                    y = 0;

                    arr = der = abj = true;
                }
                else
                {
                    int num = rand() % 4 + 1;
                    cambioDireccion(num);
                }
            }

            if (arr == false)
            {
                if (movi[UP])
                {
                    changeAnimation(&arriba);
                    //std::cout << "ME MUEVO IZQUIERDA" << endl;
                    y -= velocidad;
                    x = 0;
                    der = izq = abj = true;
                }
                else
                {
                    int num = rand() % 4 + 1;
                    cambioDireccion(num);
                }
            }

            if (abj == false)
            {
                if (movi[DOWN])
                {
                    changeAnimation(&abajo);
                    //std::cout << "ME MUEVO IZQUIERDA" << endl;
                    y += velocidad;
                    x = 0;
                    arr = izq = der = true;
                }
                else
                {
                    int num = rand() % 4 + 1;
                    cambioDireccion(num);
                }
            }

            //// std::cout << "CUANDO SE MUEVE Mov. enemy X: " << x << " Y: " << y << endl;

            // Arma->getSprite()->move(posX,posY);
        }
    }
    if (tipo == 2)
    {
        if (der == false)
        {
            if (movi[RIGHT])
            {
                changeAnimation(&derecha);
                //std::cout << "ME MUEVO DERECHA DERECHA" << endl;
                x += velocidad;
                y = 0;
                arr = izq = abj = true;
            }
            else
            {
                // std::cout << "ME HE CHOCADO" << endl;
                //int num = rand()%4+1;
                cambioDireccion(3); // para que se mueva a la izqu
            }
        }

        if (izq == false)
        {
            if (movi[LEFT])
            {
                changeAnimation(&izquierda);
                //std::cout << "ME MUEVO IZQUIERDA" << endl;
                x -= velocidad;
                y = 0;

                arr = der = abj = true;
            }
            else
            {
                //int num = rand()%4+1;
                cambioDireccion(4);
            }
        }
    }
    if (tipo == 3 && onTarget)
    {
        if (ataca)
        {
            cdAttack.restart();
            ataca = false;
            arr = true;
            der = true;
            abj = true;
            izq = true;
            if (arr)
            {
                //   cout<<"INTENTO DISPARAR ARRIBA \n";
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 13, enemy.getPosition().y - 15, 1, 50);
                proyectiles.push_back(proyec);
            }
            if (abj)
            {
                //cout<<"INTENTO DISPARAR ABAJO \n";
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 13, enemy.getPosition().y + 15, 2, 50);
                proyectiles.push_back(proyec);
            }
            if (der)
            {
                //cout<<"INTENTO DISPARAR DERECHA \n";
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 15, enemy.getPosition().y + 12, 3, 50);
                proyectiles.push_back(proyec);
            }
            if (izq)
            {
                //cout<<"INTENTO DISPARAR IZQUIERDA \n";
                Proyectil *proyec = new Proyectil(enemy.getPosition().x, enemy.getPosition().y + 15, 4, 50);
                proyectiles.push_back(proyec);
            }
        }
    }
    if (tipo == 4)
    {
        if (ataca)
        {
            ataca = false;
            cdAttack.restart();
            if (dir_4 == 1)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 13, enemy.getPosition().y + 15, 2, 50);
                proyectiles.push_back(proyec);
                dir_4 = 2;
            }
            else if (dir_4 == 2)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x, enemy.getPosition().y + 15, 4, 50);
                proyectiles.push_back(proyec);
                dir_4 = 3;
            }
            else if (dir_4 == 3)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 13, enemy.getPosition().y - 15, 1, 50);
                proyectiles.push_back(proyec);
                dir_4 = 4;
            }
            else if (dir_4 == 4)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 15, enemy.getPosition().y + 12, 3, 50);
                proyectiles.push_back(proyec);
                dir_4 = 1;
            }
        }
    }
    if (tipo == 5)
    { // EL boss te sigue y te tira proyectiles

        if (movi[RIGHT] && distaX >= 0)
        {
            changeAnimation(&derecha);
            x += velocidad;
            //cambioDireccion()
        }

        if (movi[LEFT] && distaX < 0)
        {
            changeAnimation(&izquierda);
            x -= velocidad;
        }
        else
        {
            movi[LEFT] = true;
        }

        if (movi[DOWN] && distaY >= 0)
        {
            changeAnimation(&abajo);
            y += velocidad;
        }
        else
        {
            movi[DOWN] = true;
        }

        if (movi[UP] && distaY < 0)
        {
            changeAnimation(&arriba);
            y -= velocidad;
        }
        else
        {
            movi[UP] = true;
        }
        if (ataca)
        {
            ataca = false;
            cdAttack.restart();
            if (dir_4 == 1)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 13, enemy.getPosition().y + 15, 2, 50);
                proyectiles.push_back(proyec);
                dir_4 = 2;
            }
            else if (dir_4 == 2)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x, enemy.getPosition().y + 15, 4, 70);
                proyectiles.push_back(proyec);
                dir_4 = 3;
            }
            else if (dir_4 == 3)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 13, enemy.getPosition().y - 15, 1, 90);
                proyectiles.push_back(proyec);
                dir_4 = 4;
            }
            else if (dir_4 == 4)
            {
                Proyectil *proyec = new Proyectil(enemy.getPosition().x + 15, enemy.getPosition().y + 12, 3, 110);
                proyectiles.push_back(proyec);
                dir_4 = 1;
            }
        }
    }

    if (tipo != 3)
    {
        enemy.move(x * d, y * d);
        coli[UP].move(x * d, y * d);
        coli[DOWN].move(x * d, y * d);
        coli[LEFT].move(x * d, y * d);
        coli[RIGHT].move(x * d, y * d);
    }
}

void Enemigo::cambioDireccion(int n)
{
    // std::cout << "Cambio dir: " << n << std::endl;
    switch (n)
    {
    case 1:
        der = true;
        abj = true;
        arr = false;
        izq = true;

        movi[UP] = true;
        break;

    case 2:
        der = true;
        abj = false;
        arr = true;
        izq = true;

        movi[DOWN] = true;
        break;

    case 3:
        der = true;
        abj = true;
        arr = true;
        izq = false;

        movi[LEFT] = true;
        break;

    case 4:
        der = false;
        abj = true;
        arr = true;
        izq = true;

        movi[RIGHT] = true;
        break;

        //cout<<"izquierda"<<izq<<"\n";
        //cout<<"derecha"<< der<< "\n";
        //cout<<"arriba"<< arr<<"\n";
        //cout<<"abajo"<< abj<<"\n";
    }
}

sf::RectangleShape Enemigo::getColision(int n)
{
    sf::RectangleShape e;

    switch (n)
    {
    case 1:
        e = coli[UP];
        break;
    case 2:
        e = coli[DOWN];
        break;
    case 3:
        e = coli[LEFT];
        break;
    case 4:
        e = coli[RIGHT];
        break;
    default:
        break;
    }

    return e;
}

void Enemigo::compruebaMov(int x, bool v)
{
    //// std::cout<<"Antes: "<<movimiento[x];

    if (x == 1)
    {
        movi[UP] = v;
    }
    else if (x == 2)
    {
        movi[DOWN] = v;
    }
    else if (x == 3)
    {
        movi[LEFT] = v;
    }
    else if (x == 4)
    {
        movi[RIGHT] = v;
    }
}

int Enemigo::getPosX()
{
    return x;
}

int Enemigo::getPosY()
{
    return y;
}

int Enemigo::getVida()
{
    return health;
}

sf::RectangleShape &Enemigo::getShape()
{
    return enemy;
}

sf::RectangleShape &Enemigo::getcoli(int i)
{
    return coli[i];
}

int Enemigo::Ataque()
{
    return damage;
}

std::vector<Proyectil *> Enemigo::getProyectiles()
{
    return proyectiles;
}

int Enemigo::getTipo()
{
    return tipo;
}
void Enemigo::borrarProyectil(int i)
{
    delete proyectiles.at(i);
    proyectiles.erase(proyectiles.begin() + i);
}