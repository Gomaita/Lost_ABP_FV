#include "Sprite.h"

SpriteSheet::SpriteSheet(Textura texture, int r1, int r2, int c1, int c2, int w, int h)
{

    rect = sf::IntRect(r1 * w, c1 * h, w, h);
    rect2 = sf::IntRect(r2 * w, c2 * h, w, h);
    sprite = sf::Sprite(texture.getTex(), rect);
}

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::~SpriteSheet()
{
}

SpriteSheet::SpriteSheet(Textura *texture, int r, int c, int w, int h)
{

    rect = sf::IntRect(r, c, w, h);
    sprite = sf::Sprite(texture->getTex(), rect);
}

SpriteSheet::SpriteSheet(sf::Texture *texture, int r, int c, int w, int h)
{

    rect = sf::IntRect(r, c, w, h);
    sprite = sf::Sprite(*texture);
}

//Equivalente a sprite.setTextureRect(frame)
void SpriteSheet::Draw()
{
    // const sf::IntRect srcRect(col * m_frameWidth, row * m_frameHeight, m_frameWidth, m_frameHeight);
    sprite.setTextureRect(rect);
}

void SpriteSheet::move(float x, float y)
{
    sprite.move(x, y);
}

void SpriteSheet::move(sf::Vector2f v)
{
    sprite.move(v);
}

float SpriteSheet::getFrameWidth()
{
    return m_frameWidth;
}

float SpriteSheet::getFrameHeight()
{
    return m_frameHeight;
}

float SpriteSheet::getposX()
{
    return sprite.getPosition().x;
}

float SpriteSheet::getposY()
{
    return sprite.getPosition().y;
}

// Gets the position of the sprite.
sf::Vector2f SpriteSheet::getPosition()
{

    return m_Position;
}

// Returns sprite
sf::Sprite &SpriteSheet::getSprite()
{
    return sprite;
}

sf::FloatRect SpriteSheet::getSize()
{
    return sprite.getGlobalBounds();
}

void SpriteSheet::setTexture(sf::Texture &textura)
{
    sprite.setTexture(textura);
}

void SpriteSheet::setSpriteScale(sf::Vector2f &scale)
{
    sprite.setScale(scale);
}

void SpriteSheet::setSpriteScale(float scaleX, float scaleY)
{
    sprite.setScale(scaleX, scaleY);
}

// Sets the position of the sprite.
void SpriteSheet::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void SpriteSheet::setRotation(float f)
{
    sprite.setRotation(f);
}
// Sets the position of sprite using Vector2f.
void SpriteSheet::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos.x, pos.y);
}

void SpriteSheet::setColor(sf::Color color)
{
    sprite.setColor(color);
}

void SpriteSheet::setOrigin(const float xCenter, const float yCenter)
{
    sprite.setOrigin(xCenter, yCenter);
}
