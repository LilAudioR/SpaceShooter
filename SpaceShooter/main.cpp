#if _DEBUG
#pragma comment(lib, "SFML-system-d")
#pragma comment(lib, "SFML-graphics-d")
#pragma comment(lib, "SFML-window-d")
#else
#pragma comment(lib, "SFML-system")
#pragma comment(lib, "SFML-graphics")
#pragma comment(lib, "SFML-window")
#endif

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

int main()
{
	sf::RenderWindow window;
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	videoMode.width = 800u;
	videoMode.height = 800u;

	window.create(videoMode, "SFML Window");

	sf::Texture pinguTexture;
	pinguTexture.loadFromFile("Assets/Pingu.png");
	sf::Sprite pinguSprite;
	pinguSprite.setTexture(pinguTexture);

	sf::Sprite pingu2Sprite;
	pingu2Sprite.setTexture(pinguTexture);

	float pinguX = 100.0f;
	float pinguY = 100.0f;

	while (window.isOpen())
	{
		window.clear(sf::Color(0, 150, 255));
		pinguX += (rand() % 2 == 0 ? (-1) : 1) * 0.33f;
		pinguY += (rand() % 2 == 0 ? (-1) : 1) * 0.33f;

		pingu2Sprite.setPosition(pinguX, pinguY);

		// Draw here
		//window.draw(pinguSprite);
		window.draw(pingu2Sprite);

		window.display();
	}

	return 0;
}