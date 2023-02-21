#pragma once
#include <vector>

class Ccollider
{
public:

	Ccollider();
	Ccollider(float _radius);

	float GetRadius();

private:

	float radius;
};