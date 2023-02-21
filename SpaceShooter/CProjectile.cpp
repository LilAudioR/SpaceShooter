#include "CProjectile.h"


CProjectile::CProjectile()
  : Damage(10.0)
{
}

CProjectile::CProjectile(int _damage)
  : Damage(_damage)
{
}

CProjectile::CProjectile(sf::Vector2f pos, sf::Vector2f vel)
  : Damage(10.0)
{
  position = pos;
  velocity = vel;
}

void CProjectile::CollisionOverlap(CGameObject* _other)
{
  CGameObject* temp_enemy = dynamic_cast<CGameObject*>(_other);
  if (temp_enemy)
  {
    //CODE HERE TO DESTRUCT THE PROJECTILE
  }

}