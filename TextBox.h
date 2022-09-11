#pragma once

#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

//Represents a Textbox
class Textbox
{
private:
	sf::Text textbox;
	std::stringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;
public:
	void setTextbox(int size, sf::Color color, bool selected, sf::Font& font, sf::Vector2f position);
	void setLimit(bool hasLim, int lim);
	std::string getText();

	void inputCharacter(int charTyped,std::string& nick);
	void deleteCharacter();

	void draw(sf::RenderWindow* window);
	void update(sf::Event ev,std::string& nick);
};

