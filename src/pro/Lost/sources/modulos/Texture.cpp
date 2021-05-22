#include "Texture.h"

Textura::Textura()
{
}

bool Textura::loadTex(std::string s)
{

    return t.loadFromFile(s);
}