#include "Game.h"
#include "Player.h"
#include "CProjectile.h"

void CGame::Run()
{
	videoMode.width = 800u;
	videoMode.height = 800u;
	window.create(videoMode, "Operation: Protect Pingu From The Aliens That Are Trying To Abduct Him");

	CPlayer player;
	actors.push_back(&player);

	while (window.isOpen())
	{
		window.clear(sf::Color(0, 150, 255));

		sf::Event E;
		while(window.pollEvent(E))

		// TICK LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Tick();
		}

		// ADD NEW OBJECTS LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			CPlayer* p = dynamic_cast<CPlayer*>(actors[i]);
			if (p)
			{
				if (p->FiringProjectile)
				{
					actors.push_back(new CProjectile(p->GetPosition(), sf::Vector2f(0.0f, 5.0f)));
					p->FiringProjectile = false;
				}
			}
		}

		// DRAW LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Draw(window);
		}

		window.display();
	}
}