#include "Collider.h"
#include "CRectangleCollider.h"

Ccollider::Ccollider()
  : radius(0.f)
{
}

Ccollider::Ccollider(float _radius)
  : radius(_radius)
{
}

float Ccollider::GetRadius()
{
  return radius;
}
