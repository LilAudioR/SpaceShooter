#include "Pingu.h"
#include <iostream>

CPingu::CPingu() : CGameObject("Assets\\Pingu.png", { 550,600 })
{
	sprite.setScale(0.3f, 0.3f);
}

void CPingu::Tick()
{
	sprite.setPosition(position.x += _moveSpeed, 0);

	sf::Vector2f position = sprite.getPosition();
	std::cout << position.x << " " << position.y << "\n";
}

void CPingu::CollisionOverlap(CGameObject* _other)
{
}
