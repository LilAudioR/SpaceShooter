#include "GameObject.h"

CGameObject::CGameObject()
{
	texture.loadFromFile("Assets/Pingu.png");
	sprite.setTexture(texture);
	position = sf::Vector2f(0.0f, 0.0f);
	velocity = sf::Vector2f(0.0f, 0.0f);
	MakeCollider();
}

CGameObject::CGameObject(std::string FilePath, sf::Vector2f pos)
{
	texture.loadFromFile(FilePath);
	sprite.setTexture(texture);
	position = pos;
	velocity = sf::Vector2f(0.0f, 0.0f);
	MakeCollider();
}

CGameObject::CGameObject(std::string FilePath, sf::Vector2f pos, sf::Vector2f vel)
{
	texture.loadFromFile(FilePath);
	sprite.setTexture(texture);
	position = pos;
	velocity = vel;
	MakeCollider();
}

/*void CGameObject::Tick()
{
}*/

void CGameObject::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}

sf::Vector2f CGameObject::GetPosition() {
	return position;
}
void CGameObject::SetPosition(float x, float y) {
	position = sf::Vector2f(x, y);
}
void CGameObject::SetPosition(sf::Vector2f pos) {
	position = pos;
}

sf::Vector2f CGameObject::GetVelocity() {
	return velocity;
}
void CGameObject::SetVelocity(float x, float y) {
	velocity = sf::Vector2f(x, y);
}
void CGameObject::SetVelocity(sf::Vector2f vel) {
	velocity = vel;
}

Ccollider* CGameObject::GetCollider()
{
	return &collider;
}

void CGameObject::MakeCollider()
{
	Ccollider(std::max(sprite.getLocalBounds().height, sprite.getLocalBounds().width) / 2.f);
}
