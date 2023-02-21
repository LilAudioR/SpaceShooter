#pragma once
#include <vector>
#include "GameObject.h"

class CCollisionManager
{
public:
  
  CCollisionManager(std::vector<CGameObject*> _actors); 

  void CheckCollisions();
  float CalcDistance(CGameObject* actor1, CGameObject* actor2);

private:
  std::vector<CGameObject*> actors;
};


//REMINDER FOR TOMORROW:
// Construct a CCollisionManager at the time of constructing CGame, and pass on actors to it as the reference.
// I think when new actors are added, or any actor is destroyed, the actors list in CCollisionManager needs to be updated.

