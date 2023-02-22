#include "CEnemy.h"
#include <iostream>

CEnemy::CEnemy()
  : CGameObject("Assets\\shipPink_manned.png", { 300, 100 }), health(100)
{
}

void CEnemy::Tick(float dt) {
    //std::cout << "Enemy HP: " << health.GetHealth() << std::endl;
    //std::cout << "Enemy radius: " << collider->GetRadius() << std::endl;
  FollowPingu();
}

void CEnemy::CollisionOverlap(CGameObject* _other)
{
  CProjectile* projectile = dynamic_cast<CProjectile*>(_other); 
  if (projectile)
  {
    health.TakeDamage(projectile->GetDamage());
    
    if (!health.StillAlive())
    {
      PendingDeath = true;
    }
    
  }
}

void CEnemy::SetPingu(CPingu &_Pingu)
{
  Pingu = &_Pingu;
}

void CEnemy::FollowPingu()
{
  SetPosition(Pingu->GetPosition().x, position.y);
}




