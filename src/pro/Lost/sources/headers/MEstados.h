
#pragma once
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "Contexto.h"

class MEstados
{
public:
	virtual void Inicializar() = 0;
	virtual void event(sf::Event event, sf::RenderWindow &window, float) = 0;
	virtual void update(sf::RenderWindow &window, float) = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	void ChangeState(Contexto *game, MEstados *state)
	{
		game->ChangeState(state);
	}
};
