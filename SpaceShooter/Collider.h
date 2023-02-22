#pragma once
#include <vector>

class Ccollider
{
public:

	Ccollider();
	Ccollider(float _radius);
	virtual ~Ccollider() {}

	float GetRadius();

private:

	float radius;
};