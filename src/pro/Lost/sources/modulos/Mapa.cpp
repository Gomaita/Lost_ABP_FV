#include "Mapa.h"

Mapa::Mapa(int nivel, int v)
{
    nivelactual = nivel;
    leerMapa(nivel, v);
    setAtributos();
    leerDatos();
    cargarTexturas();
    creaMapaSprites();
    crearArraysES();

    nombre_salida.reserve(50);
    x_salida.reserve(50);
    y_salida.reserve(50);
    nombre_enemigo.reserve(50);
    x_enemigo.reserve(50);
    y_enemigo.reserve(50);
}

Mapa::~Mapa()
{
    _width = _height = _tileWidth = _tileHeight = 0;
    _numLayers = 0;
    nivelactual = 0;
    num = 0;
    //std::cout<<"borramos capas\n";

    for (int i = 0; i < _numLayers; i++)
    {
        for (int j = 0; j < _height; j++)
        {
            delete _tilemap[i][j];
        }
        delete _tilemap[i];
    }
    delete _tilemap;

    //std::cout<<"borramos tilemap\n";
    for (int l = 0; l < _numLayers; l++)
    {
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                delete _tilemapSprite[l][y][x];
            }
            delete _tilemapSprite[l][y];
        }
        delete _tilemapSprite[l];
    }

    delete _tilemapSprite;

    //std::cout<<"borramos tilemap\n";

    for (size_t j = 0; j < enemigos.size(); j++)
    {
        //delete enemigos.at(j);
        enemigos.erase(enemigos.begin() + j);
    }

    //std::cout<<"borramos mapa de sprites\n";

    nombre_salida.clear();
    x_salida.clear();
    y_salida.clear();
    //std::cout<<"borramos vectores\n";

    nombre_enemigo.clear();
    x_enemigo.clear();
    y_enemigo.clear();
    //std::cout<<"borramos vectores pt.2  \n";
}

void Mapa::leerDatos()
{
    //std::cout << "Width: " << _width << endl;
    //std::cout << "Height: " << _width << endl;
    //std::cout << "Imagen Tileset: " << img << endl;
    //std::cout << "Filename: " << filename << endl;
    //std::cout << "Capa: " << layer << endl;
}

void Mapa::leerMapa(int nivel, int variante)
{
    //std::cout<<"NIVEEEEEEEEEEEEEEL"<<nivel;

    if (nivel != 0)
    {
        stringstream ss;
        ss << nivel;
        string str = ss.str();
        //std::cout<<str;

        //int varianteM = variante[nivel-1];
        if (variante == 0)
        {
            variante = 1;
        }

        //std::cout<<"Variante: "<<variante<<endl;

        stringstream ss2;
        ss2 << variante;

        string str2 = ss2.str();
        //std::cout<<str2;

        string fichero = "resources/mapa/tmx/Sala_1_" + str + "_" + str2 + ".tmx"; //Nombre de mapas tiene que ser: mapa_X_Y.tmx  x= nivel(id), y = variante para mapa
        //std::cout<<fichero;
        doc.LoadFile(fichero.c_str());
        //doc.LoadFile("resources/mapa/tmx/Sala_1_1_2.tmx");
    }
    else
    {
        doc.LoadFile("resources/mapa/tmx/Sala_1_0_1.tmx");
    }

    //Tamaño del mapa y de los tiles
    map = doc.FirstChildElement("map");
}

void Mapa::setAtributos()
{
    std::cerr << "\nLectura de atributos del Tilemap" << endl;
    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight);

    //Carga de TMX con TinyXML - Imagen del tileset
    img = map->FirstChildElement("tileset")->FirstChildElement("image");
    filename = img->Attribute("source");
    layer = map->FirstChildElement("layer");
}

void Mapa::cargarTexturas()
{
    // ****** CREA LA TEXTURA *********** //
    _numLayers = 0;
    _tilesetTexture = new Texture;
    if (!_tilesetTexture->loadFromFile(filename))
    {
        std::cerr << "No ha podido cargar las texturas" << std::endl;
        exit(0);
    }

    //Capas de mi TMX
    std::cerr << "Numero layers antes:" << _numLayers << std::endl;
    while (layer)
    {
        _numLayers++;
        layer = layer->NextSiblingElement("layer");
    }
    std::cerr << "Numero layers despues:" << _numLayers << std::endl;

    //Reservamos memoria para mapa
    //std::cout << "Reservamos memoria para el nº de capas" << endl;
    layer = map->FirstChildElement("layer"); //Apunta a la primera capa
    _tilemap = new int **[_numLayers];       //Asignamos el nº de capas

    //Asignación de capas
    for (int i = 0; i < _numLayers; i++)
    {
        // height of the tilemap
        _tilemap[i] = new int *[_height];
        for (int j = 0; j < _height; j++)
        {
            // width of the tilemap
            _tilemap[i][j] = new int[_width];
        }
    }

    //Cargando los GIDs de multiples capas
    //data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");

    int cont = 0; //Capa en la que nos encontramos en el bucle
    while (layer)
    {
        data = layer->FirstChildElement("data")->FirstChildElement("tile");
        while (data)
        {
            for (int i = 0; i < _height; i++)
            {
                for (int j = 0; j < _width; j++)
                {
                    data->QueryIntAttribute("gid", &_tilemap[cont][i][j]);
                    //Avanzo al siguiente tag
                    data = data->NextSiblingElement("tile");
                }
            }
        }
        layer = layer->NextSiblingElement("layer");
        cont++;
    }

    //Cargamos el mapa
    //std::cout << "Numero de layers: " << _numLayers << endl;
}

void Mapa::creaMapaSprites()
{
    //std::cout << "Reserva de Sprites" << endl;
    _tilemapSprite = new sf::Sprite ***[_numLayers];

    for (int l = 0; l < _numLayers; l++)
    {
        _tilemapSprite[l] = new sf::Sprite **[_height];
        for (int y = 0; y < _height; y++)
        {
            _tilemapSprite[l][y] = new sf::Sprite *[_width];
            for (int x = 0; x < _width; x++)
            {
                _tilemapSprite[l][y][x] = new sf::Sprite;
            }
        }
    }

    // ****** SACAR COLUMNAS Y FILAS DE LA TEXTURA ************//
    int columnas = _tilesetTexture->getSize().x / _tileWidth;
    int filas = _tilesetTexture->getSize().y / _tileHeight;

    cout << "x: " << _tilesetTexture->getSize().x << endl;
    cout << "y: " << _tilesetTexture->getSize().y << endl;
    cout << "Columnas: " << columnas << endl
         << "Filas: " << filas << endl;
    // ****** CREAR EL SPRITE CON LA TEXTURA DE ARRIBA *********** //
    //Tile especifico de mi tileset - Formado por cada uno de los elementos de mi tileset
    _tilesetSprite = new sf::Sprite[filas * columnas];

    int n = 0;

    for (int y = 0; y < filas; y++)
    {
        for (int x = 0; x < columnas; x++)
        {
            _tilesetSprite[n].setTexture(*_tilesetTexture);
            _tilesetSprite[n].setTextureRect(sf::IntRect(x * _tileWidth, y * _tileHeight, _tileWidth, _tileHeight));
            ////std::cout << _tilesetSprite[n].getTextureRect().left << endl;
            n++;
        }
    }

    for (int l = 0; l < _numLayers; l++)
    {
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                int gid = _tilemap[l][y][x] - 1;
                //Ahora empiza asignar los sprites a los (gids)

                if (gid > 0 && gid < _width * _height)
                {
                    //Si fuera 0 no creo sprite
                    _tilemapSprite[l][y][x] = new sf::Sprite(*_tilesetTexture, _tilesetSprite[gid].getTextureRect());
                    _tilemapSprite[l][y][x]->setPosition(x * _tileWidth, y * _tileHeight);
                    ////std::cout << x*_tileWidth << " + " << y*_tileHeight << endl;
                }
                else
                {
                    _tilemapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}

sf::Vector2f Mapa::getViewPosition()
{
    tinyxml2::XMLElement *object;

    object = map->FirstChildElement("objectgroup");
    std::string nameObject;
    int x = 0;
    int y = 0;

    while (object)
    {
        nameObject = (std::string)object->Attribute("name");

        if (nameObject.compare("view") == 0)
        {
            object = object->FirstChildElement("object");

            object->QueryIntAttribute("x", &x);
            object->QueryIntAttribute("y", &y);

            break;
        }
        else
        {
            object = object->NextSiblingElement("objectgroup");
        }
    }

    return sf::Vector2f(x, y);
}

void Mapa::draw(sf::RenderWindow &window, Jugador *j)
{

    for (int l = 0; l < _numLayers; l++)
    {
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                if (_tilemapSprite[l][y][x] != NULL)
                {
                    //Dibujado por capas, primero jugador luego elementos del mapa
                    if (l == 1)
                    {
                        j->draw(window);
                    }
                    window.draw(*(_tilemapSprite[l][y][x]));
                    if (!enemigos.empty())
                    {
                        for (unsigned i = 0; i < enemigos.size(); i++)
                        {
                            // //std::cout<<"DIBUJA ENEMIGOS EN MUNDO.\n";
                            enemigos.at(i)->draw(window);
                        }
                    }
                }
            }
        }
    }
}

void Mapa::setActiveLayer(int layer)
{
    _activeLayer = layer;
}

void Mapa::mapaColisiones(Jugador *player)
{

    // Para la capa 2 que es la de las colisiones
    //setActiveLayer(1);
    for (int l = 0; l < _numLayers; l++)
    {
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                if (_tilemapSprite[l][y][x] != NULL)
                {
                    int gid = _tilemap[l][y][x] - 1;
                    sf::FloatRect pos;
                    //Ahora empiza asignar los sprites a los (gids)
                    if ((nivelactual != 0) && (gid == 7 || gid == 33 || gid == 34 || gid == 42 || gid == 99 || gid == 198 || gid == 224 || gid == 230 || gid == 255 || gid == 256 || gid == 257 || gid == 258 || gid == 259 || gid == 288 || gid == 289 || gid == 292 || gid == 293 || gid == 322 || gid == 323 || gid == 481 || gid == 484))
                    {
                        pos = _tilemapSprite[l][y][x]->getGlobalBounds();
                        for (unsigned j = 1; j <= 4; j++)
                        {
                            if (checkCollision(player->getColision(j).getGlobalBounds(), pos))
                            {
                                player->compruebaMov(j, false);
                            }
                        }
                    }
                    else if ((nivelactual == 0) && (gid == 161 || gid == 162 || gid == 163 || gid == 164 || gid == 165 || gid == 166 || gid == 116 || gid == 117 || gid == 139 || gid == 140 || gid == 55 || gid == 118 || gid == 83 || gid == 82 || gid == 170 || gid == 169 || gid == 115 || gid == 103 || gid == 104 || gid == 105 || gid == 126 || gid == 127 || gid == 141 || gid == 149 || gid == 150 || gid == 127))
                    {
                        pos = _tilemapSprite[l][y][x]->getGlobalBounds();
                        for (unsigned j = 1; j <= 4; j++)
                        {
                            if (checkCollision(player->getColision(j).getGlobalBounds(), pos))
                            {
                                player->compruebaMov(j, false);
                            }
                        }
                    }
                }
            }
        }
    }
}

void Mapa::mapaColisiones(Enemigo *enemy)
{

    // Para la capa 2 que es la de las colisiones
    //setActiveLayer(1);
    for (int l = 0; l < _numLayers; l++)
    {
        for (int y = 0; y < _height; y++)
        {
            for (int x = 0; x < _width; x++)
            {
                if (_tilemapSprite[l][y][x] != NULL)
                {
                    int gid = _tilemap[l][y][x] - 1;
                    sf::FloatRect pos;
                    //Ahora empiza asignar los sprites a los (gids)
                    if ((nivelactual != 0) && (gid == 33 || gid == 34 || gid == 42 || gid == 99 || gid == 198 || gid == 224 || gid == 230 || gid == 255 || gid == 256 || gid == 257 || gid == 258 || gid == 259 || gid == 288 || gid == 289 || gid == 292 || gid == 293 || gid == 322 || gid == 323 || gid == 481 || gid == 484))
                    {
                        pos = _tilemapSprite[l][y][x]->getGlobalBounds();
                        for (unsigned j = 1; j <= 4; j++)
                        {
                            if (checkCollision(enemy->getColision(j).getGlobalBounds(), pos))
                            {
                                //  //std::cout << "Entro a colision enemigo" << endl;
                                enemy->compruebaMov(j, false);
                            }
                        }
                    }
                    else if ((nivelactual == 0) && (gid == 161 || gid == 162 || gid == 163 || gid == 164 || gid == 165 || gid == 166 || gid == 116 || gid == 117 || gid == 139 || gid == 140 || gid == 55 || gid == 118 || gid == 83 || gid == 82 || gid == 170 || gid == 169 || gid == 115 || gid == 103 || gid == 104 || gid == 105 || gid == 126 || gid == 127 || gid == 141 || gid == 149 || gid == 150 || gid == 127))
                    {
                        pos = _tilemapSprite[l][y][x]->getGlobalBounds();
                        for (unsigned j = 1; j <= 4; j++)
                        {
                            if (checkCollision(enemy->getColision(j).getGlobalBounds(), pos))
                            {
                                // //std::cout << "Entro a colision enemigo" << endl;
                                enemy->compruebaMov(j, false);
                            }
                        }
                    }
                }
            }
        }
    }
}

bool Mapa::checkCollision(sf::FloatRect a, sf::FloatRect b)
{
    if (a.intersects(b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Mapa::checkCollision(Enemigo e, Proyectil p)
{
    if (e.getShape().getGlobalBounds().intersects(p.getBounds()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Mapa::crearArraysES()
{
    tinyxml2::XMLElement *object;
    object = map->FirstChildElement("objectgroup");
    std::string capa;
    std::string spawnpoint;
    std::string nombreenemigo;
    int posx_salida = 0;
    int posy_salida = 0;
    while (object)
    {
        capa = (std::string)object->Attribute("name");
        if (capa.compare("Salida") == 0)
        {
            object = object->FirstChildElement("object");
            while (object)
            {
                spawnpoint = (std::string)object->Attribute("name");
                //std::cout<<"Nombre spawn:"<<spawnpoint;
                object->QueryIntAttribute("x", &posx_salida);
                //std::cout<<"x:"<<posx_salida;
                object->QueryIntAttribute("y", &posy_salida);
                //std::cout<<"y:"<<posy_salida;

                nombre_salida.push_back(spawnpoint);
                x_salida.push_back(posx_salida);
                y_salida.push_back(posy_salida);

                object = object->NextSiblingElement("object");
            }
        }
        else
        {
            object = object->NextSiblingElement("objectgroup");
        }
    }
}
//LA FUNCION DE ABAJO TIENE QUE VER LA COORD ACTUAL DEL JUGADOR, CADA VEZ QUE SE MUEVE COMPARARLO CON TODAS LAS POSIBLES SALIDAS Y SI ESTA EN UNA DE ESTAS EJECUTAR ESTA FUNCION
//QUE CUANDO DETECTE QYE SI ESTA SOBRE UNA DE LAS SALIDAS INVOCARA A GENERARNUEVO MAPA

int Mapa::cambiodemapa(Jugador *player)
{
    int value = 0;
    for (unsigned int poscambiox = 0; poscambiox < x_salida.size(); poscambiox++)
    {
        if (nombre_salida[poscambiox].at(2) == 'A' && (int)player->getPlayer().getPosition().x >= x_salida[poscambiox] && ((int)player->getPlayer().getPosition().x) <= x_salida[poscambiox] + 16 && (int)player->getPlayer().getPosition().y >= y_salida[poscambiox] - 16 && (int)player->getPlayer().getPosition().y <= y_salida[poscambiox] + 40)
        {
            //std::cout<<"hola\n";
            //std::cout << "NOMBRE SALIDA == 'A': " << nombre_salida[poscambiox].at(1);
            sala = nombre_salida[poscambiox].at(1);
            puntoRespawn = nombre_salida[poscambiox];
            value = sala - 48;
            //std::cout << "Num. sala: " << value << endl;
            if (value == 0)
            {
                value = 1099;
            }
            break;
        }
        if (nombre_salida[poscambiox].at(2) != 'A' && (int)player->getPlayer().getPosition().x + 8 >= x_salida[poscambiox] - 16 && (int)player->getPlayer().getPosition().x + 8 <= x_salida[poscambiox] + 40 && (int)player->getPlayer().getPosition().y + 8 >= y_salida[poscambiox] && (int)player->getPlayer().getPosition().y + 8 <= y_salida[poscambiox] + 16)
        {
            //std::cout << "NOMBRE SALIDA != 'A': " << nombre_salida[poscambiox].at(1);
            sala = nombre_salida[poscambiox].at(1);
            puntoRespawn = nombre_salida[poscambiox];
            value = sala - 48;
            //std::cout << "Num. sala: " << value << endl;
            if (player->getHasKey() == false && value == 9)
            {
                value = 9999;
            }
            if (player->getHasKey() == true && value == 9)
            {
                value = 9;
            }

            if (value == 0)
            {
                value = 1099;
            }

            break;
        }
    }
    return value;
}

Vector2i Mapa::puntoInicio(string nombre)
{
    Vector2i value;

    tinyxml2::XMLElement *object;
    object = map->FirstChildElement("objectgroup");

    std::string capa;
    std::string spawnpoint;

    //std::cout << "Nombre: " << nombre << endl;

    if (!nombre.empty())
    {
        while (object)
        {
            capa = (std::string)object->Attribute("name");
            if (capa.compare("Entrada") == 0)
            {
                object = object->FirstChildElement("object");
                while (object)
                {
                    spawnpoint = (std::string)object->Attribute("name");
                    if (spawnpoint.compare(nombre) == 0)
                    {
                        object->QueryIntAttribute("x", &value.x);
                        object->QueryIntAttribute("y", &value.y);
                        break;
                    }
                    else
                    {
                        object = object->NextSiblingElement("object");
                    }
                }
            }
            else
            {
                object = object->NextSiblingElement("objectgroup");
            }
        }
    }
    else
    {
        value.x = value.y = 170;
    }

    //std::cout << "Value.x = " << value.x << endl;
    //std::cout << "Value.y = " << value.y << endl;

    return value;
}

void Mapa::setPosEnemy()
{
    tinyxml2::XMLElement *object;
    object = map->FirstChildElement("objectgroup");
    std::string capa;
    std::string nombreenemigo;
    int xenemigo = 0;
    int yenemigo = 0;

    while (object)
    {
        capa = (std::string)object->Attribute("name");
        if (capa.compare("Enemigo") == 0)
        {
            object = object->FirstChildElement("object");
            while (object)
            {
                nombreenemigo = object->Attribute("name");
                object->QueryIntAttribute("x", &xenemigo);
                object->QueryIntAttribute("y", &yenemigo);

                nombre_enemigo.push_back(nombreenemigo);
                x_enemigo.push_back(xenemigo);
                y_enemigo.push_back(yenemigo);

                Enemigo *enemigo;

                if (nombreenemigo == "Esqueleto")
                {
                    // El magias
                    enemigo = new Enemigo(100, 5.0f, 3, xenemigo, yenemigo, 0);
                    //std::cout << "Enemigo 1 \n";
                }
                else if (nombreenemigo == "Fantasma")
                {
                    //el que te sigue
                    enemigo = new Enemigo(200, 5.0f, 1, xenemigo, yenemigo, 10);
                    //enemigo = new Enemigo(100, 50.5f, 2);
                    //std::cout << "Enemigo 2 \n";
                }
                else if (nombreenemigo == "Orco")
                {
                    // el de izq derecha
                    enemigo = new Enemigo(300, 5.0f, 2, xenemigo, yenemigo, 10);
                    //std::cout << "Enemigo 3 \n";
                }
                else if (nombreenemigo == "Bruja")
                {
                    //enemigo = new Enemigo(100, 50.5f, 4);
                    enemigo = new Enemigo(100, 5.0f, 4, xenemigo, yenemigo, 0);
                    //std::cout << "Enemigo 4 \n";
                }
                else if (nombreenemigo == "Boss")
                {
                    enemigo = new Enemigo(800, 5.0f, 5, xenemigo, yenemigo, 10);
                    //std::cout << "Enemigo 5 \n";
                }

                /*enemigo->setX(xenemigo);
                enemigo->setY(yenemigo);*/

                enemigos.push_back(enemigo);

                for (unsigned int x = 0; x < enemigos.size(); x++)
                {
                    //std::cout<<"Enemigo ["<<x<<"] insertado"<<enemigos[x]<<"\n";
                }
                object = object->NextSiblingElement("object");
            }
        }
        else
        {
            object = object->NextSiblingElement("objectgroup");
        }
    }
}

std::vector<Enemigo *> Mapa::getEnemigos()
{
    return enemigos;
}

string Mapa::getNombreSala()
{
    return puntoRespawn;
}

void Mapa::setVariante(int m)
{
    variante = m;
}

void Mapa::eliminaEnemigo(int x)
{
    if (enemigos.at(x) != NULL)
    {
        //Enemigo* e = enemigos.at(x);
        //delete enemigos.at(x);
        enemigos.erase(enemigos.begin() + x);
        //delete e;
    }
}

void Mapa::compruebaEnemigos(float d, float a, float b)
{
    if (!enemigos.empty())
    {
        for (size_t i = 0; i < enemigos.size(); i++)
        {
            if (!enemigos.at(i)->haMuerto())
            {
                enemigos.at(i)->update(d, a, b);
            }
            else
            {
                delete enemigos.at(i);
                enemigos.erase(enemigos.begin() + i);
            }
        }
    }
}

sf::Vector2f Mapa::encontrarLlave()
{
    tinyxml2::XMLElement *object;
    object = map->FirstChildElement("objectgroup");
    std::string capa;
    std::string nombrellave;
    int xllave = 0;
    int yllave = 0;

    while (object)
    {
        capa = (std::string)object->Attribute("name");
        if (capa.compare("Llave") == 0)
        {
            object = object->FirstChildElement("object");
            while (object)
            {
                nombrellave = object->Attribute("name");
                object->QueryIntAttribute("x", &xllave);
                object->QueryIntAttribute("y", &yllave);
                return sf::Vector2f(xllave, yllave);
                object = object->NextSiblingElement("object");
            }
        }
        else
        {
            object = object->NextSiblingElement("objectgroup");
        }
    }

    return sf::Vector2f(xllave, yllave);
}