#pragma once
#include <vector>

class CRectangleCollider;

class Ccollider
{
public:

	Ccollider();
	Ccollider(float _radius);

	virtual void func() {}

	float GetRadius();

private:

	float radius;
};