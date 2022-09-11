#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
/// <summary>
/// Monster with average dmg and hp
/// </summary>
class Drowner:public Enemy
{
private:
	void initTexture() override;
	void initSprite() override;
	void initVariables() override;
public:
	//constructor
	Drowner(float posx, float posy);
};

