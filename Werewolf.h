#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
/// <summary>
/// Werewolf is slow but have a lot of hp and dmg 
/// </summary>
class Werewolf :public Enemy
{
private:
	void initTexture() override;
	void initSprite() override;
	void initVariables() override;
public:
	Werewolf(float posx, float posy);
};
