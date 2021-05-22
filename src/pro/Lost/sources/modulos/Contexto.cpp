#include "Contexto.h"
#include "MEstados.h"

Contexto *Contexto::pinstance = 0;

Contexto *Contexto::Instance()
{
    if (pinstance == 0)
    {
        pinstance = new Contexto;
    }
    return pinstance;
}

void Contexto::Inicializar()
{
    this->cambio = true;
    mEstados.reserve(100);
}

void Contexto::ChangeState(MEstados *s)
{
    //Almacena e inicia el nuevo estado
    //std::cout << "\nTamaño pila de estados: " << this->mEstados.size() << "\n";
    this->mEstados.push_back(s);
    //std::cout << "Cambio de estado. \n";
    this->mEstados.back()->Inicializar();
    //std::cout<<this->mEstados.size()<<"\n";
}

void Contexto::event(sf::Event event, sf::RenderWindow &window, float d)
{
    this->mEstados.back()->event(event, window, d);
}

void Contexto::update(sf::RenderWindow &window, float d)
{
    //Dejar al estado actualizar el juego
    this->mEstados.back()->update(window, d);
}
void Contexto::draw(sf::RenderWindow &window)
{
    // let the state draw the screen
    window.clear();
    mEstados.back()->draw(window);
    window.display();
}
