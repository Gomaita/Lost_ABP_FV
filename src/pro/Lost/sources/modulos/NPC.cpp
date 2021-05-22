#include "NPC.h"
#include <iostream>

NPC::NPC(std::string nom, int x, int y)
{
	this->setName(nom);
	//this->texture.loadFromFile(file);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->rect.setSize(Vector2f(32, 32));
	text.setFont(font);
	text.setCharacterSize(15);
	//text.setFillColor(Color::Black);
}

NPC::~NPC()
{
	//std::cout << "An NPC has been destroyed." << std::endl;
}

void NPC::update()
{
}

void NPC::setName(std::string name)
{
}