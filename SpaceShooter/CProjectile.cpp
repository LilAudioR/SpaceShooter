#include "CProjectile.h"


CProjectile::CProjectile()
  : Damage(10.0)
{
  texture.loadFromFile("Assets/laserYellow1.png");
  sprite.setTexture(texture);
  position = sf::Vector2f(0.f, 0.f);
  velocity = sf::Vector2f(0.f, 0.f);
}

CProjectile::CProjectile(int _damage)
  : Damage(_damage)
{
  texture.loadFromFile("Assets/laserYellow1.png");
  sprite.setTexture(texture);
  position = sf::Vector2f(0.f, 0.f);
  velocity = sf::Vector2f(0.f, 0.f);
}

CProjectile::CProjectile(sf::Vector2f pos, sf::Vector2f vel)
  : Damage(10.0)
{
  texture.loadFromFile("Assets/laserYellow1.png");
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