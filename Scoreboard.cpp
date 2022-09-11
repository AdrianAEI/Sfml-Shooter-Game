#include "Scoreboard.h"


Scoreboard::Scoreboard()
{
	if (!font.loadFromFile("Fonts/OpenSans-Regular.ttf"))
	{
		std::cout << "Error with load font" << std::endl;
	}
	if (!this->scoreboardBackgroundTex.loadFromFile("Textures/tempTlo.png"))
	{
		std::cout << "Error with load text" << std::endl;
	};
	this->scoreboardBackground.setTexture(this->scoreboardBackgroundTex);
	this->scoreboardText.setFont(font);
	this->scoreboardText.setCharacterSize(120);
	this->scoreboardText.setFillColor(sf::Color::Red);
	this->scoreboardText.setPosition(600,100);
	this->scoreboardText.setString("Scoreboard");

}

Scoreboard::~Scoreboard()
{

}
//<regex>
bool Scoreboard::correctNick(std::string nick)
{	
	std::regex correct("^([A-Za-z0-9\S]){1,10}$");
	if(std::regex_match(nick, correct))
	{
		return true;
	}
	else
	{
		sf::Text text;
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		text.setString(nick+" is invalid! Try again!");
		text.setPosition(sf::Vector2f(100, 300));
		return false;
	}
}

void Scoreboard::seeScoreboard()
{
	//<ranges>
	std::ranges::sort(this->records, std::ranges::greater{});
	float posy=300;
	for (int i = 0; i < 10; i++)
	{
		std::stringstream temp;
		std::string s;
		temp << "NICK:" << std::setw(20) << records[i].second << std::setw(20) <<records[i].first;
		temp >> s;
		recordTable[i].setFont(font);
		recordTable[i].setFillColor(sf::Color::Red);
		recordTable[i].setString(temp.str());//tak duzo lepiej 
		recordTable[i].setPosition(sf::Vector2f(600, posy));
		posy += 50;
	}
}
//<filesystem>
void Scoreboard::saveToFile(std::string& nick,int score)
{
	std::filesystem::path filePath("records.txt");
	if (std::filesystem::exists(filePath))
	{
		std::ofstream myfile(filePath,std::ios::app);
		if(myfile)
		{
			myfile << score <<" "<< nick << std::endl;
			myfile.close();
		}
		else
		{
			std::cout << "Error with file" << std::endl;
		}
	}
	else
	{
		std::cout << "Error with path" << std::endl;
	}
}

void Scoreboard::loadFromFile()
{
	//no overwrite
	records.clear();
	std::filesystem::path filePath("records.txt");
	if (std::filesystem::exists(filePath))
	{
		std::ifstream myfile(filePath);
		if (myfile)
		{
			while (myfile >> record.first >> record.second)
			records.push_back(record);
		}
		else
		{
			std::cout << "Error with file" << std::endl;
		}
	}
	else
	{
		std::cout << "Error with path" << std::endl;
	}
}
void Scoreboard::renderScoreboard(sf::RenderWindow*& window)
{
	window->draw(this->scoreboardBackground);
	window->draw(this->scoreboardText);
	for (int i = 0; i < 10; i++)
	{
		window->draw(this->recordTable[i]);
	}
}

