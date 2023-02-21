#include "Game.h"
#include "Player.h"
#include "CProjectile.h"
#include "Pingu.h"

void CGame::Run()
{
	videoMode.width = 1300u;
	videoMode.height = 850u;
	window.create(videoMode, "Operation: Protect Pingu From The Aliens That Are Trying To Abduct Him");
	sf::Texture t;
	t.loadFromFile("Assets\\bg.png");
	sf::Sprite s(t);

	CPingu pingu;
	CPlayer player;
	actors.push_back(&player);
	actors.push_back(&pingu);

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.draw(s);

		// TICK LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Tick();
			if(actors[i]->PendingDeath)
			{
				delete actors[i];
				actors.erase(actors.begin()+i);
				i--;
			}
		}

		sf::Event E;
		while(window.pollEvent(E))

		// ADD NEW OBJECTS LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			CPlayer* p = dynamic_cast<CPlayer*>(actors[i]);
			if (p)
			{
				if (p->FiringProjectile)
				{
					actors.push_back(new CProjectile(p->GetPosition(), sf::Vector2f(0.0f, 1.0f)));
					p->FiringProjectile = false;
				}
			}
		}

		window.clear(sf::Color::White);
		window.draw(s);

		// DRAW LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Draw(window);
		}

		window.display();
	}
}