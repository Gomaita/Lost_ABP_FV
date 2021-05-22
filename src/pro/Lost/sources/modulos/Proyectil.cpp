#include "Proyectil.h"
Proyectil::Proyectil() {}

Proyectil::Proyectil(float dirx, float diry, int movi, float vel)
{
    x = dirx;
    y = diry;
    movimiento = movi;
    colision = false;
    reloj = sf::Clock();
    autodestruccion = sf::Clock();
    bala = RectangleShape(Vector2f(20.f, 20.f));
    //  bala.setOrigin(x , y );
    Velocidad = vel;

    //std::cout << "Movimiento: " << movimiento << endl;
    switch (movimiento)
    {
    case 1:
        direccion = new Animacion("./resources/Armas/proyectil.png", 53, 0.07f);
        direccion->colocarFrames(IntRect(0 * 53, 0 * 78, 53, 78), IntRect(2 * 53, 0 * 78, 53, 78));
        direccion->setPos(sf::Vector2f(x, y));
        bala.setPosition(sf::Vector2f(x, y));
        break;
    case 2:
        direccion = new Animacion("./resources/Armas/proyectil.png", 53, 0.07f);
        direccion->colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));
        direccion->setPos(sf::Vector2f(x, y));
        bala.setPosition(sf::Vector2f(x, y));
    case 3:
        direccion = new Animacion("./resources/Armas/proyectil.png", 53, 0.07f);
        direccion->colocarFrames(IntRect(0 * 53, 1 * 78, 53, 78), IntRect(2 * 53, 1 * 78, 53, 78));
        direccion->setPos(sf::Vector2f(x, y));
        bala.setPosition(sf::Vector2f(x, y));
        break;
    case 4:
        direccion = new Animacion("./resources/Armas/proyectil.png", 53, 0.07f);
        direccion->colocarFrames(IntRect(0 * 53, 3 * 78, 53, 78), IntRect(2 * 53, 3 * 78, 53, 78));
        direccion->setPos(sf::Vector2f(x, y));
        bala.setPosition(sf::Vector2f(x, y));
        break;
    default:
        break;
    }
}

Proyectil::~Proyectil()
{
    delete direccion;
}

/*
void Proyectil::Colisiona(Enemigo* enemy){
    if(enemy->getShape().getGlobalBounds().intersects(bala.getGlobalBounds())){
        colision = true;
        enemy->getDamage(200);
    }
    else if(autodestruccion.getElapsedTime().asSeconds() == 5.0f){
        colision = true;
    }
}*/

void Proyectil::update(float d)
{
    //float tiempo = reloj.restart().asSeconds();

    //std::cout<<"POS X DE BALA: "<< x<<" POS Y DE BALA"<< y << endl;
    switch (movimiento)
    {
    case 1: // arriba
        direccion->update(d, Vector2f(0, -Velocidad));
        bala.move(Vector2f(0, -Velocidad * d));
        break;
    case 2: // arriba
        direccion->update(d, Vector2f(0, Velocidad));
        bala.move(Vector2f(0, Velocidad * d));
        break;
    case 3: // arriba
        direccion->update(d, Vector2f(Velocidad, 0));
        bala.move(Vector2f(Velocidad * d, 0));
        break;
    case 4: // arriba
        direccion->update(d, Vector2f(-Velocidad, 0));
        bala.move(Vector2f(-Velocidad * d, 0));
        break;

    default:
        break;
    }

    /*
    //direccion->update(d, Vector2f(x+12, y+12));
    for(unsigned int i = 0; i < enemies.size(); i++){
       // if(enemies[i]){
            //Colisiona(enemies[i]);
            destruido = true;
        //}
    }*/
    if (autodestruccion.getElapsedTime().asSeconds() > 0.8)
    {
        destruido = true;
    }
}

void Proyectil::setColisiona(bool valor)
{
    colision = valor;
}

bool Proyectil::getColisiona()
{
    return colision;
}

void Proyectil::draw(sf::RenderWindow &Window)
{
    if (!colision || !destruido)
    {
        direccion->Draw(Window);
        // Window.draw(bala);
    }
}

bool Proyectil::getDestruido()
{
    return destruido;
}

void Proyectil::setDestruido(bool cambio)
{
    destruido = cambio;
}

sf::FloatRect Proyectil::getBounds()
{
    return bala.getGlobalBounds();
}