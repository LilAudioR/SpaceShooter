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
	void CreateProjectileBuffer();
	void UpdateProjectileBuffer(CPlayer* _player);

private:
	sf::RenderWindow window;
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	std::vector<CGameObject*> actors;
	constexpr static int projectile_buffer_size = 64;
	CProjectile projectiles[projectile_buffer_size];
	std::queue<CProjectile*> projectile_buffer;
};