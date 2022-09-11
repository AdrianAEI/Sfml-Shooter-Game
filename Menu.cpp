#include "Menu.h"

Menu::Menu()
{
	if (!font.loadFromFile("Fonts/Daughter of Fortune.ttf"))
	{
		std::cout << "Error with load font" << std::endl;
	}
	if (!this->menuBackgroundTex.loadFromFile("Textures/menuBackground.png"))
	{
		std::cout << "Error with load world" << std::endl;
	};
	this->menuBackground.setTexture(this->menuBackgroundTex);
}

Menu::~Menu()
{
}

void Menu::initMenu(sf::RenderWindow*& window)
{
	this->window = window;
	this->selectedButton = 0;
	title.setFont(font);
	title.setCharacterSize(120);
	title.setFillColor(sf::Color::Red);
	title.setString("Witcher Dungeon The Game");
	title.setPosition(sf::Vector2f(500, 50));

	button[0].setFont(font);
	button[0].setCharacterSize(80);
	button[0].setFillColor(sf::Color::Red);
	button[0].setString("Play");
	button[0].setPosition(sf::Vector2f(350, 300));

	button[1].setFont(font);
	button[1].setCharacterSize(80);
	button[1].setFillColor(sf::Color::White);
	button[1].setString("Scoreboard");
	button[1].setPosition(sf::Vector2f(350, 500));

	button[2].setFont(font);
	button[2].setCharacterSize(80);
	button[2].setFillColor(sf::Color::White);
	button[2].setString("Exit");
	button[2].setPosition(sf::Vector2f(350, 700));

}

void Menu::initChoice()
{
	this->selectedButton = 0;
	button[0].setFont(font);
	button[0].setFillColor(sf::Color::Red);
	button[0].setString("Geralt ");
	button[0].setPosition(sf::Vector2f(850, 300));

	button[1].setFont(font);
	button[1].setFillColor(sf::Color::White);
	button[1].setString("Milva");
	button[1].setPosition(sf::Vector2f(850, 500));

	button[2].setFont(font);
	button[2].setFillColor(sf::Color::White);
	button[2].setString("Triss");
	button[2].setPosition(sf::Vector2f(850, 700));
}

void Menu::RenderWindow()
{
	this->window->draw(this->menuBackground);
	this->window->draw(this->title);
	for(int i = 0; i<3; i++)
	{
		this->window->draw(button[i]);
	}
}

void Menu::moveUp()
{
	if (selectedButton - 1 >= 0)
	{
		button[selectedButton].setFillColor(sf::Color::White);
		selectedButton--;
		button[selectedButton].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedButton + 1 <3)
	{
		button[selectedButton].setFillColor(sf::Color::White);
		selectedButton++;
		button[selectedButton].setFillColor(sf::Color::Red);
	}
}

void Menu::initTexture()
{
	if (!this->menuBackgroundTex.loadFromFile("Textures/menuBackground.png"))
	{
		std::cout << "Error with load world" << std::endl;
	};
	this->menuBackground.setTexture(this->menuBackgroundTex);
}
