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
  CGameObject* temp_enemy = dynamic_cast<CGameObject*>(_other); //REPLACE THIS WITH CENEMY ONCE WE HAVE IT
  if (temp_enemy)
  {
    //CODE HERE TO DESTRUCT THE PROJECTILE
  }

}