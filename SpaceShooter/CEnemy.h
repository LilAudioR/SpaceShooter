#pragma once
#include "GameObject.h"
#include "Health.h"
#include "CProjectile.h"

class CEnemy : public CGameObject
{
public:
  CEnemy();
  void Tick(float) override;
  void CollisionOverlap(CGameObject* _other) override;

private:
  CHealth health;
};

