#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <queue>
#include "Player.h"
#include "GameObject.h"
#include "CProjectile.h"

class CGame
{
public:
	void Run(); //Game loop goes here
	void CreateProjectileBuffer(int buffer_size);
	void UpdateProjectileBuffer(CPlayer* _player);

private:
	sf::RenderWindow window;
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	std::vector<CGameObject*> actors;
	std::queue<CProjectile*> projectile_buffer;
};