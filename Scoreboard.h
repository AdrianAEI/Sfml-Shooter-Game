#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <regex>
#include <ranges>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
/// <summary>
/// Represents a scoreboard in main menu
/// </summary>
class Scoreboard
{
private:
	std::vector<std::pair<int, std::string>> records;
	sf::Font font;
	sf::Text scoreboardText;
	sf::Texture scoreboardBackgroundTex;
	sf::Sprite scoreboardBackground;
	std::pair<int,std::string> record;
	//up to 10 records
	sf::Text recordTable[10];
public:
	Scoreboard();
	~Scoreboard();
	//<regex> check is nick correct
	bool correctNick(std::string nick);
	//<filesystem> and <ranges>
	void seeScoreboard();
	void saveToFile(std::string& nick, int score);
	void loadFromFile();
	void renderScoreboard(sf::RenderWindow*& window);
};
