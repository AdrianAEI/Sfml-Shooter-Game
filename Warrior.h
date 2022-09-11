#pragma once
#define IMMORTAL 1000000
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Character.h"
//Represents a playable character
class Warrior:public Character
{
public:
	Warrior();
	//Immortal for 3 seconds
	void ability(bool& threadFree) override;
private:
	void initVariables() override;
	void initTexture() override;
	void initSprite() override;
};

