#include "Pingu.h"
#include <iostream>

CPingu::CPingu() : CGameObject("Assets\\Pingu.png", { 550,600 })
{
	sprite.setScale(0.3f, 0.3f);
}

void CPingu::Tick(float dt)
{
	_totalTime += dt;
	float calculatedXPos;
	float totalWaddleTime = 2.0f;

	if (_totalTime > totalWaddleTime)
	{
		_totalTime -= totalWaddleTime;
	}

	float percentageOfWaddle = _totalTime / totalWaddleTime;
	float waddleOffset = 100;
	float windowMiddlePos = 550;

	calculatedXPos = sinf(2 * 3.141f * percentageOfWaddle) * waddleOffset;

	//move pingu position
	SetPosition(calculatedXPos + windowMiddlePos, 600);

	sprite.setRotation(sinf(8 * 3.141f * percentageOfWaddle) * 10);
}

void CPingu::CollisionOverlap(CGameObject* _other)
{

}
