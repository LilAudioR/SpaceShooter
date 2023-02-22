#pragma once
#include "GameObject.h"

class CBackground : public CGameObject
{
public:
	CBackground();
	void Tick() override;
	virtual void CollisionOverlap(CGameObject* _other);
private:

};