#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

#include "GameObject.h"

class CGame
{
public:
	void Run(); //Game loop goes here
private:
	sf::RenderWindow window;
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	std::vector<CGameObject*> actors;
};