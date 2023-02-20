#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Collider.h"

class CGameObject
{
public:
	CGameObject();
	CGameObject(std::string);
	virtual void Tick();
	virtual void Draw();
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f velocity;
	Ccollider Collider();
};