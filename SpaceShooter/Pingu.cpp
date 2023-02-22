#include "Pingu.h"
#include <iostream>

CPingu::CPingu() : CGameObject("Assets\\Pingu.png", { 550,600 })
{
	sprite.setScale(0.3f, 0.3f);
}

void CPingu::Tick(float dt)
{
}

void CPingu::CollisionOverlap(CGameObject* _other)
{
}
