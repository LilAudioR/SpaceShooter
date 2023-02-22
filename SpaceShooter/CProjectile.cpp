#include "CProjectile.h"
#include <iostream>

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
    //PendingDeath = true;
      Explode();
      velocity = { 0, 0 };
  }
  
}

void CProjectile::Tick(float dt)
{
  position -= velocity * dt;
  //std::cout << collider->GetRadius() << std::endl;
}

void CProjectile::Explode()
{
    texture.loadFromFile("Assets/laserYellow_burst.png");
    sprite.setTexture(texture);
}

float CProjectile::GetDamage()
{
  return Damage;
}
