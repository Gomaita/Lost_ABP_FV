#pragma once
#include <string>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include "Animacion.h"

class NPC
{
private:
    int posX, posY;
    RectangleShape rect;
    Sprite sprite;
    Font font;
    Text text;
    Texture texture;

public:
    NPC(string, int, int);
    ~NPC();
    RectangleShape &getRect();
    Sprite &getSprite();
    Text &getText();
    Texture &getTexture();
    Font &getFont();
    std::string intText;
    void update();
    void draw(sf::RenderWindow);
    void setIntersectionText(std::string intText);
    void setName(std::string name);
    std::string getIntersectionText();
};