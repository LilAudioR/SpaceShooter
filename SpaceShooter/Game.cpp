#include "Game.h"

void CGame::Run()
{
	videoMode.width = 800u;
	videoMode.height = 800u;
	window.create(videoMode, "UFO Game");

	// Player player();
	// actors.push_back(&player);

	while (window.isOpen())
	{
		// TICK LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Tick();
		}

		// DRAW LOOP
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Draw(window);
		}

		window.display();
	}
}