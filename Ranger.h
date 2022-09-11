#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Character.h"
/// <summary>
/// Ranger is another hero to play
/// </summary>
class Ranger :public Character
{
public:
	Ranger();
	//more dmg and movement speed 
	void ability(bool& threadFree) override;
private:
	void initVariables() override;
	void initTexture() override;
	void initSprite() override;
};

