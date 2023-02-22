#include "Health.h"

CHealth::CHealth(int maxHealth)
{
    _maxHealth = maxHealth;
    _currentHealth = _maxHealth;
}

bool CHealth::StillAlive()
{
    if (_currentHealth > 0)
    {
        return true;
    }
    return false;
}

void CHealth::TakeDamage(int damage)
{
    _currentHealth -= damage; 
}

int CHealth::GetMaxHealth()
{
    return _maxHealth;
}

int CHealth::GetHealth()
{
    return _currentHealth;
}

