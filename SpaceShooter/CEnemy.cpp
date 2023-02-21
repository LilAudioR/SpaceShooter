#include "CEnemy.h"

CEnemy::CEnemy()
  : CGameObject("Assets\\shipPinkd.png", { 0,0 }), health(100)
{
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




