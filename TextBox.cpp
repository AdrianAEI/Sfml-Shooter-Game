#include "TextBox.h"

void Textbox::setTextbox(int size, sf::Color color, bool selected, sf::Font& font, sf::Vector2f position)
{
	this->setLimit(true, 18);
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	textbox.setFont(font);
	textbox.setPosition(position);
	isSelected = selected;

	if (selected)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}

void Textbox::setLimit(bool hasLim, int lim)
{
	hasLimit = hasLim;
	limit = lim;
}

std::string Textbox::getText()
{
	return text.str();
}


void Textbox::draw(sf::RenderWindow* window)
{
	window->draw(textbox);
}

void Textbox::inputCharacter(int charTyped, std::string& nick)
{

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		text << static_cast<char>(charTyped);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		if (text.str().length() > 0)
		{
			deleteCharacter();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		if (text.str().length() > 0)
		{
			nick = text.str();
			text.str("");
		}
	}
	textbox.setString(text.str() + "_");
}

void Textbox::deleteCharacter()
{
	std::string t = text.str();
	std::string newT = "";

	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}

void Textbox::update(sf::Event ev,std::string& nick)
{
	if (isSelected)
	{
		int charTyped = ev.text.unicode;
		if (charTyped < 128)
		{
			if (hasLimit)
			{
				if (text.str().length() <= limit)
				{
					inputCharacter(charTyped,nick);
				}
				else if (text.str().length() > limit && sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					deleteCharacter();
				}
			}
			else
			{
				inputCharacter(charTyped,nick);
			}
		}
	}
}