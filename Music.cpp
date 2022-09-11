#include "Music.h"


Music::Music()
{
	this->loadFromFile();
}

void Music::loadFromFile()
{
	music1.openFromFile("Songs/Game.ogg");
	music2.openFromFile("Songs/Menu.ogg");
}

void Music::play(int number)
{
	switch (number)
	{
	case 1:
		music1.play();
		music1.setVolume(20);
		break;
	case 2:
		music2.play();
		music2.setVolume(20);
		break;
	}
	
}
void Music::stop(int number)
{
	switch (number)
	{
	case 1:
		music1.stop();
		break;
	case 2:
		music2.stop();
		break;
	}

}
