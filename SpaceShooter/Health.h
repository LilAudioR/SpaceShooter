#pragma once

class CHealth 
{
public:
	CHealth(int maxHealth);
	bool StillAlive();
	void TakeDamage(int damage);
private:
	int _maxHealth = 100;
	int _currentHealth;
};
