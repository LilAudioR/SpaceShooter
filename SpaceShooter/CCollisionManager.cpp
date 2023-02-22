#include "CCollisionManager.h"

CCollisionManager::CCollisionManager(std::vector<CGameObject*> &_actors)
  : actors(_actors)
{
}

//Check pairwise collisions between any two actors
void CCollisionManager::CheckCollisions()
{
  int size = int(actors.size());

  for (int i = 0; i < size-1; i++)
  {
    for (int j = i+1; j < size; j++)
    {
      if(actors[i]->CollisionFlag == true && actors[j]->CollisionFlag == true)
      {
        //if (CalcDistance(actors[i], actors[j]) < actors[i]->GetCollider()->GetRadius() + actors[j]->GetCollider()->GetRadius())
        if (actors[i]->IsColliding(actors[j]))
        {
          actors[i]->CollisionOverlap(actors[j]);
          actors[j]->CollisionOverlap(actors[i]);
        }
      
      }
    }
  }

}

//Calculate the distance between two actors
float CCollisionManager::CalcDistance(CGameObject* actor1, CGameObject* actor2)
{
  sf::Vector2f lv = (actor1->GetPosition()) - (actor2->GetPosition());

  return std::sqrt(lv.x * lv.x + lv.y * lv.y);

}
