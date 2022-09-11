#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <filesystem>
/// <summary>
/// Music class
/// </summary>
class Music
{
private:
	sf::Music music1;
	sf::Music music2;
public:
	Music();
	void loadFromFile();
	void play(int number);
	void stop(int number);
};

