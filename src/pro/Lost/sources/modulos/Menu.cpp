#include "Menu.h"

Menu *Menu::instance = 0;

Menu *Menu::Instance()
{
    if (instance == 0)
    {
        instance = new Menu();
    }
    return instance;
}

void Menu::Inicializar()
{
    menu.reserve(MAX_NUMBER_ITEMS);
}

Menu::Menu()
{
    if (track.openFromFile("resources/sound/underground.ogg"))
    {
        //std::cout << "Error en audio" << std::endl;
    }

    track.setVolume(65.0);
    track.setLoop(true);
    track.play();

    //Cargamos el fondo
    tBackground = Texture();
    if (!tBackground.loadFromFile("resources/menu/fondo3.jpg"))
    {
        //std::cout << "Error en el cargado de la textura fondo3.jpg" << std::endl;
    }

    //sBackground = sf::Sprite(tBackground);
    sBackground.setTexture(tBackground);
    sBackground.setPosition(0, 0);

    fondo = Animacion("./resources/menu/Frames.png", 1280, 0.1f);
    fondo.colocarFrames(IntRect(0 * 1280, 0 * 768, 1280, 768), IntRect(11 * 1280, 0 * 768, 1280, 768));
    fondo.changeSize(1.0f, 1.0f);

    tBox = Texture();
    if (!tBox.loadFromFile("resources/menu/title.png"))
    {
        //std::cout << "Error en el cargado de la textura box.jpg" << std::endl;
    }
    sBox.setTexture(tBox);
    sBox.setScale(1.0f, 1.0f);
    sBox.setPosition(350, 100);

    selectedItem = -1;

    //Opciones del menu
    loadResources();
}

Menu::~Menu()
{
}

void Menu::loadResources()
{
    if (!tButtons.loadFromFile("resources/menu/LostLOGOnew.png"))
    {
        //std::cout << "Error en el cargado de la textura buttons.jpg" << std::endl;
    }

    sButtons.setTexture(tButtons);
    sButtons.setScale(0.60, 0.60);
    sButtons.setPosition(505, 380);
}

void Menu::draw(sf::RenderWindow &window)
{

    //window.draw(sBackground);
    fondo.Draw(window);
    window.draw(sBox);

    switch (modo)
    {
    case -1:
        if (!tButtons.loadFromFile("resources/menu/LostLOGOnew.png"))
        {
            //std::cout << "Error en el cargado de la textura new.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;

    case 0:
        if (!tButtons.loadFromFile("resources/menu/LostLOGOcontrols.png"))
        {
            //std::cout << "Error en el cargado de la textura controls.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;

    case 1:
        if (!tButtons.loadFromFile("resources/menu/LostLOGOopt.png"))
        {
            //std::cout << "Error en el cargado de la textura opt.png" << std::endl;
        }
        sButtons.setTexture(tButtons);
        break;

    case 2:
        if (!tButtons.loadFromFile("resources/menu/LostLOGOexit.png"))
        {
            //std::cout << "Error en el cargado de la textura exit.png" << std::endl;
        }
        sButtons.setTexture(tButtons);

        break;
    }

    window.draw(sButtons);
    if (modo == 0 && selectedItem == 0 && controles)
    {
        window.draw(sControls);
    }

    if (modo == 1 && selectedItem == 1 && credits)
    {
        window.draw(sCredits);
    }
}

void Menu::event(sf::Event event, sf::RenderWindow &window, float d)
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
        case sf::Keyboard::Up:
        {
            if (modo == -1)
            {
                modo = 2;
                selectedItem = 2;
                cout << "Has cambiado a selected item 2 \n";
            }
            else if (modo == 0)
            {
                modo = -1;
                selectedItem = -1;
                cout << "Has cambiado a selected item -1 \n";
            }
            else if (modo == 1)
            {
                modo = 0;
                selectedItem = 0;
                cout << "Has cambiado a selected item 0 \n";
            }
            else if (modo == 2)
            {
                modo = 1;
                selectedItem = 1;
                cout << "Has cambiado a selected item 1 \n";
            }
        }
        break;
        //Abajo
        case sf::Keyboard::Down:
        {
            if (modo == -1)
            {
                modo = 0;
                selectedItem = 0;
                cout << "Has cambiado a selected item 0 \n";
            }
            else if (modo == 0)
            {
                modo = 1;
                selectedItem = 1;
                cout << "Has cambiado a selected item 1 \n";
            }
            else if (modo == 1)
            {
                modo = 2;
                selectedItem = 2;
                cout << "Has cambiado a selected item 2 \n";
            }
            else if (modo == 2)
            {
                modo = -1;
                selectedItem = -1;
                cout << "Has cambiado a selected item -1 \n";
            }
        }
        break;
        //Enter
        case sf::Keyboard::Return:
            //std::cout << "Espacio/Enter\n";
            switch (selectedItem)
            {
            case -1: //New game
            {
                Contexto *c = Contexto::Instance();
                c->ChangeState(Opciones::Instance());
            }
            break;

            case 0: //Controls
            {
                modo = 0;
                selectedItem = 0;
                controles = true;
                if (!tControls.loadFromFile("resources/menu/controls.png"))
                {
                    //std::cout << "Error en el cargado de la textura controls.png" << std::endl;
                }
                sControls.setTexture(tControls);
                sControls.setPosition(0, 0);
            }
            break;
            case 1: //Credits
            {
                modo = 1;
                selectedItem = 1;
                credits = true;
                if (!tCredits.loadFromFile("resources/menu/Credits.png"))
                {
                    //std::cout << "Error en el cargado de la textura Credits.png" << std::endl;
                }
                sCredits.setTexture(tCredits);
                sCredits.setPosition(0, 0);
            }
            break;
            case 2: //Exit
            {
                modo = 2;
                selectedItem = 2;
                track.stop();
                window.close();
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
                selectedItem = -1;
                controles = false;
                credits = false;
            }
            else
            {
                track.stop();
                window.close();
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

void Menu::update(sf::RenderWindow &window, float d)
{
    fondo.update(d, Vector2f(0, 0));
}