#pragma once
#include "GameObject.h"

class CPingu : public CGameObject 
{
public:
	CPingu();
	void Tick() override;
	virtual void CollisionOverlap(CGameObject* _other);
protected:
	float _moveSpeed = 0.1;
};