#pragma once
#include "GameObject.h"
#include "Health.h"
#include "CProjectile.h"
#include"Pingu.h"

class CEnemy : public CGameObject
{
public:
  CEnemy();
  void Tick(float) override;
  void CollisionOverlap(CGameObject* _other) override;
  void SetPingu(CPingu &Pingu);
  void FollowPingu();

private:
  CHealth health;
  CPingu* Pingu;
};

