#include "Opciones.h"

Opciones *Opciones::instance = 0;

Opciones *Opciones::Instance()
{
    if (instance == 0)
    {
        instance = new Opciones();
    }
    return instance;
}

void Opciones::Inicializar()
{
    modo = -1;
}

Opciones::Opciones()
{
    tButtons = Texture();
    modo = -1;
    playerA = Animacion("resources/Personajes/Protagonista_chico.png", 53, 0.35f);
    playerB = Animacion("resources/menu/personaje2.png", 53, 0.35f);
    playerC = Animacion("resources/menu/personaje3.png", 53, 0.35f);
    playerD = Animacion("resources/menu/personaje4.png", 53, 0.35f);

    playerA.colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));
    playerB.colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));
    playerC.colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));
    playerD.colocarFrames(IntRect(0 * 53, 2 * 78, 53, 78), IntRect(2 * 53, 2 * 78, 53, 78));

    playerA.changeSize(2.0f, 2.0f);
    playerB.changeSize(2.0f, 2.0f);
    playerC.changeSize(2.0f, 2.0f);
    playerD.changeSize(2.0f, 2.0f);

    playerA.setPos(Vector2f(150, 360));
    playerB.setPos(Vector2f(450, 360));
    playerC.setPos(Vector2f(724, 360));
    playerD.setPos(Vector2f(1030, 360));
}

Opciones::~Opciones()
{
}

void Opciones::update(sf::RenderWindow &window, float d)
{
    playerA.update();
    playerB.update();
    playerC.update();
    playerD.update();
}

void Opciones::event(sf::Event event, sf::RenderWindow &window, float d)
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
        //Arriba
        case sf::Keyboard::Left:
        {
            if (modo == -1)
            {
                modo = 2;
                cout << "Has cambiado a modo 2 \n";
            }
            else if (modo == 0)
            {
                modo = -1;
                cout << "Has cambiado a modo -1 \n";
            }
            else if (modo == 1)
            {
                modo = 0;
                cout << "Has cambiado a modo 0 \n";
            }
            else if (modo == 2)
            {
                modo = 1;
                cout << "Has cambiado a modo 1 \n";
            }
        }
        break;
        //Abajo
        case sf::Keyboard::Right:
        {
            if (modo == -1)
            {
                modo = 0;
                cout << "Has cambiado a modo 0 \n";
            }
            else if (modo == 0)
            {
                modo = 1;
                cout << "Has cambiado a modo 1 \n";
            }
            else if (modo == 1)
            {
                modo = 2;
                cout << "Has cambiado a modo 2 \n";
            }
            else if (modo == 2)
            {
                modo = -1;
                cout << "Has cambiado a modo -1 \n";
            }
        }
        break;
        //Enter
        case sf::Keyboard::Return:
            //std::cout << "Espacio/Enter\n";
            switch (modo)
            {
            case -1: //DAN
            {
                Contexto *c = Contexto::Instance();
                c->ChangeState(Juego::Instance(1, true));
            }
            break;

            case 0: //LYSSANDRA
            {
                modo = 0;
                Contexto *c = Contexto::Instance();
                c->ChangeState(Juego::Instance(2, true));
            }
            break;
            case 1: //ION
            {
                modo = 1;
                Contexto *c = Contexto::Instance();
                c->ChangeState(Juego::Instance(3, true));
            }
            break;
            case 2: //IDRIL
            {
                modo = 2;
                Contexto *c = Contexto::Instance();
                c->ChangeState(Juego::Instance(4, true));
            }
            break;
            default:
                break;
            }
            break;

        case sf::Keyboard::Escape:
            if (modo == 0 || modo == 1)
            {
                modo = -1;
            }
            /*else{
                        track.stop();
                        window.close();
                    }*/
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Opciones::draw(sf::RenderWindow &window)
{
    switch (modo)
    {
    case -1:
        if (!tButtons.loadFromFile("resources/menu/Dan.png"))
        {
            //std::cout << "Error en el cargado de la textura Dan.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;

    case 0:
        if (!tButtons.loadFromFile("resources/menu/Lyssandra.png"))
        {
            //std::cout << "Error en el cargado de la textura Lyssandra.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;

    case 1:
        if (!tButtons.loadFromFile("resources/menu/Ion.png"))
        {
            //std::cout << "Error en el cargado de la textura Ion.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;

    case 2:
        if (!tButtons.loadFromFile("resources/menu/Idril.png"))
        {
            //std::cout << "Error en el cargado de la textura Idril.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;
    }

    window.draw(sButtons);
    playerA.Draw(window);
    playerB.Draw(window);
    playerC.Draw(window);
    playerD.Draw(window);
}
