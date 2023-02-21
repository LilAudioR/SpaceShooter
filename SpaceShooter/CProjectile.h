#pragma once
#include "GameObject.h"
#include "CEnemy.h"
#include <typeinfo>

class CProjectile : public CGameObject
{
public:
  CProjectile();
  CProjectile(int _damage);
  CProjectile(sf::Vector2f, sf::Vector2f);
  void CollisionOverlap(CGameObject* _other) override;
  void Tick() override;
  void Explode();

private:
  float Damage;

};

