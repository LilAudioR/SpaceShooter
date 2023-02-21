#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "GameObject.h"

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual void Tick() override;
	void CollisionOverlap(CGameObject* _other) override;
	bool FiringProjectile = false;
protected:
	float _speed = 10;
};