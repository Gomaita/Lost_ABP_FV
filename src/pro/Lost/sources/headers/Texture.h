#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Textura
{
private:
    sf::Texture t;
    float x, y;

public:
    Textura();
    bool loadTex(std::string s);
    sf::Texture &getTex()
    {
        return t;
    }
};