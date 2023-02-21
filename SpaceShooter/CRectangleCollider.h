#pragma once
#include "Collider.h"

class CRectangleCollider : public Ccollider
{
public:
	CRectangleCollider();
	CRectangleCollider(float, float);
	float x, y;
};

