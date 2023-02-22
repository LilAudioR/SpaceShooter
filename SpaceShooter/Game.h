#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <queue>

#include "GameObject.h"

class CGame
{
public:
	void Run(); //Game loop goes here
	void CreateProjectileBuffer(int buffer_size);
private:
	sf::RenderWindow window;
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	std::vector<CGameObject*> actors;
};