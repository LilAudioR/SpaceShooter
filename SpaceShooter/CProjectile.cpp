#include "CProjectile.h"


CProjectile::CProjectile()
  : CGameObject("Assets/laserYellow1.png", {0, 0}), Damage(10.0)
{
  sprite.setTexture(texture);
  position = sf::Vector2f(0.f, 0.f);
  velocity = sf::Vector2f(0.f, 0.f);
}

CProjectile::CProjectile(int _damage)
  : CGameObject("Assets/laserYellow1.png", { 0, 0 }), Damage(_damage)
{
  sprite.setTexture(texture);
  position = sf::Vector2f(0.f, 0.f);
  velocity = sf::Vector2f(0.f, 0.f);
}

CProjectile::CProjectile(sf::Vector2f pos, sf::Vector2f vel)
  : CGameObject("Assets/laserYellow1.png", pos), Damage(10.0)
{
  sprite.setTexture(texture);
  position = pos;
  velocity = vel;
}

void CProjectile::CollisionOverlap(CGameObject* _other)
{
  CEnemy* enemy = dynamic_cast<CEnemy*>(_other);
  if (enemy)
  {
    PendingDeath = true;
  }
}

void CProjectile::Tick()
{
  position -= velocity;
  CheckForOutOfBounds();
}

void CProjectile::CheckForOutOfBounds()
{
  float BoundSize = 2000;
  if (position.y > BoundSize || position.y < -1 * BoundSize || position.x > BoundSize || position.x < -1 * BoundSize)
  {
    PendingDeath = true;
  }
}

float CProjectile::GetDamage()
{
  return Damage;
}
