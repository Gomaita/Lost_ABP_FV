
#pragma once
#include "Texture.h"

class SpriteSheet
{
private:
	sf::Sprite sprite;
	sf::Uint8 m_frameLeft;
	sf::Uint8 m_frameTop;
	sf::Vector2f m_Position;
	sf::IntRect rect;
	sf::IntRect rect2;
	sf::Uint8 m_frameWidth;
	sf::Uint8 m_frameHeight;
	int col, row;

public:
	SpriteSheet();
	SpriteSheet(Textura texture, int, int, int, int, int, int);
	SpriteSheet(Textura *texture, int, int, int, int);
	SpriteSheet(sf::Texture *texture, int, int, int, int);
	virtual ~SpriteSheet();
	void Tick(sf::Time);
	void Draw();
	float getFrameWidth();
	float getFrameHeight();
	float getposX();
	float getposY();
	sf::Vector2f getPosition();
	sf::Sprite &getSprite();
	sf::FloatRect getSize();
	void setTexture(sf::Texture &);
	void move(float, float);
	void move(sf::Vector2f);
	void setSpriteScale(sf::Vector2f &scale);
	void setSpriteScale(float scaleX, float scaleY);
	void setRotation(float);
	void setPosition(float, float);
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);
	void setOrigin(float xCenter, float yCenter);
};
