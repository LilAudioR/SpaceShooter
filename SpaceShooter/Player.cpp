#include "Player.h"

CPlayer::CPlayer() : CGameObject()//pass texture for player (string to look for png)
{

}

void CPlayer::Tick()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //MOVE UP
        position.y -= _speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //MOVE DOWN
        position.y += _speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //MOVE LEFT
        position.x -= _speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //MOVE RIGHT
        position.x += _speed;
    }
}
