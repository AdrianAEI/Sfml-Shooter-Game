#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
/// <summary>
/// Ghul is faster then drowner but have less hp 
/// </summary>
class Ghul:public Enemy
{
private:
	void initTexture() override;
	void initSprite() override;
	void initVariables() override;
public:
	Ghul(float posx, float posy);
};
