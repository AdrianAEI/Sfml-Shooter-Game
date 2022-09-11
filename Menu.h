#pragma once
#include <SFML/Graphics.hpp>
#include "Scoreboard.h"
/// <summary>
/// Represents a main menu
/// </summary>
class Menu
{
private:
	int selectedButton;
	sf::Font font;
	sf::Text button[3];
	sf::Text title;
	sf::Texture menuBackgroundTex;
	sf::Sprite menuBackground;
	sf::RenderWindow* window;
public:
	Menu();
	~Menu();
	int GetPressed() { return selectedButton; }
	void initMenu(sf::RenderWindow*& window);
	void initChoice();
	void RenderWindow();
	void moveUp();
	void moveDown();;
	void initTexture();
};

