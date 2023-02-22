#include "GameObject.h"
#include "CRectangleCollider.h"

CGameObject::CGameObject()
{
	texture.loadFromFile("Assets/bg.png");
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

bool CGameObject::IsColliding(CGameObject* other)
{
	CRectangleCollider* rect = dynamic_cast<CRectangleCollider*>(other->GetCollider());
	if (rect)
	{
		return GetPosition().x < rect->x ||
			GetPosition().x + sprite.getGlobalBounds().width < rect->x + other->sprite.getGlobalBounds().width ||
			GetPosition().y < rect->y ||
			GetPosition().y + sprite.getGlobalBounds().height < rect->y + other->sprite.getGlobalBounds().height;
	}
	sf::Vector2f lv = GetPosition() - (other->GetPosition());
	return std::sqrt(lv.x * lv.x + lv.y * lv.y) < GetCollider()->GetRadius() + other->GetCollider()->GetRadius();
}

bool CGameObject::IsCrossing(CGameObject* other)
{
	return false;
}

Ccollider* CGameObject::GetCollider()
{
	return collider;
}

void CGameObject::MakeCollider()
{
	//Ccollider(std::max(sprite.getLocalBounds().height, sprite.getLocalBounds().width) / 2.f);
	collider = new Ccollider(std::max(sprite.getLocalBounds().height, sprite.getLocalBounds().width) / 2.f);
}