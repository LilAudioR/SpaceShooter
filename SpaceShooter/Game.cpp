#include "Game.h"
#include "Player.h"
#include "CProjectile.h"
#include "Pingu.h"
#include "CEnemy.h"
#include <vector>
#include "Background.h"
#include "CCollisionManager.h"


void CGame::Run()
{
	videoMode.width = 1300u;
	videoMode.height = 850u;
	window.create(videoMode, "Operation: Protect Pingu From The Aliens That Are Trying To Abduct Him");
	sf::Clock timer;

	CPingu pingu;
	CPlayer player;
	CEnemy enemy;
	CBackground backgroud;
	actors.push_back(&player);
	actors.push_back(&pingu);
	actors.push_back(&enemy);

	CCollisionManager manager(actors);
	CreateProjectileBuffer(256);

	while (window.isOpen())
	{

		float deltaTime = timer.getElapsedTime().asSeconds();
		timer.restart();

		window.clear(sf::Color::White);

		manager.CheckCollisions();

		// TICK LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Tick(deltaTime);
			if(actors[i]->PendingDeath)
			{
				CGameObject* temp = actors[i];
				actors.erase(actors.begin() + i);
				i--;
			}
		}

		sf::Event E;
		while (window.pollEvent(E))
		{
			if (E.type == sf::Event::Closed)
				window.close();
		}

		// ADD NEW OBJECTS LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			CPlayer* p = dynamic_cast<CPlayer*>(actors[i]);
			if (p)
			{
				if (p->FiringProjectile)
				{
					//actors.push_back(new CProjectile(p->GetPosition(), sf::Vector2f(0.0f, 1000.0f)));
					//p->FiringProjectile = false;
					UpdateProjectileBuffer(p);
				}
			}
		}
		backgroud.Draw(window);
		// DRAW LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Draw(window);
		}

		window.display();
	}
}

void CGame::CreateProjectileBuffer(int buffer_size)
{
	CProjectile* projectilePtr = new CProjectile[buffer_size];

	for (int i = 0; i < buffer_size; i++)
	{
		projectile_buffer.push(&projectilePtr[i]);
		projectilePtr[i].SetPosition(-5000, -5000);
		actors.push_back(&projectilePtr[i]);
	}
}

void CGame::UpdateProjectileBuffer(CPlayer* p)
{
	projectile_buffer.push(projectile_buffer.front());
	projectile_buffer.back()->SetPosition(p->GetPosition());
	projectile_buffer.back()->SetVelocity(0.0f, 1000.0f);
	projectile_buffer.pop();
	p->FiringProjectile = false;
}

