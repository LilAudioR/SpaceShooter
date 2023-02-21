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
	CGameObject(std::string, sf::Vector2f);
	CGameObject(std::string, sf::Vector2f, sf::Vector2f);

	virtual void Tick() = 0;
	virtual void Draw(sf::RenderWindow&); //Draw loop needs to take an sf::RenderWindow reference

	void MakeCollider();
	virtual void CollisionOverlap(CGameObject* _other) = 0;
	bool CollisionFlag = false;
	bool PendingDeath = false;
	Ccollider* GetCollider();


	sf::Vector2f GetPosition();
	void SetPosition(float, float);
	void SetPosition(sf::Vector2f);
	sf::Vector2f GetVelocity();
	void SetVelocity(float, float);
	void SetVelocity(sf::Vector2f);

	bool IsColliding(CGameObject*);
	bool IsCrossing(CGameObject*);


protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f velocity;
	Ccollider collider;
};