#include "Fin.h"

Fin *Fin::instance = 0;

Fin *Fin::Instance()
{
    if (instance == 0)
    {
        instance = new Fin();
    }
    return instance;
}

void Fin::Inicializar()
{
}

Fin::Fin()
{
    //Cargamos el fondo
    tBackground = Texture();
    if (!tBackground.loadFromFile("resources/menu/muerte.png"))
    {
        //std::cout << "Error en el cargado de la textura muerte.png" << std::endl;
    }

    sBackground = sf::Sprite(tBackground);
    sBackground.setPosition(0, 0);

    viewFin = sf::View();
    viewFin.zoom(0.9);

    f = sf::Font();

    if (!f.loadFromFile("resources/font/alagard.ttf"))
    {
        exit(0);
    }

    titleText = sf::Text();
    titleText.setFont(f);
    titleText.setCharacterSize(20);
    titleText.setString("PRESS ESC TO RETURN MAIN MENU");
    titleText.setPosition(sf::Vector2f(470.0, 700.0));
}

Fin::~Fin()
{
}

void Fin::draw(sf::RenderWindow &window)
{
    //Posicionamos la vista en el centro
    //viewFin.setCenter(window.getSize().x/2,window.getSize().y/2);
    window.setView(window.getDefaultView());
    window.draw(sBackground);
    window.draw(titleText);
}

void Fin::event(sf::Event event, sf::RenderWindow &window, float d)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        track.stop();
        window.close();
        break;
    case sf::Event::KeyPressed:
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
        {
            Contexto *contex = Contexto::Instance();
            contex->ChangeState(Menu::Instance());
        }
        break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Fin::update(sf::RenderWindow &window, float d)
{
}