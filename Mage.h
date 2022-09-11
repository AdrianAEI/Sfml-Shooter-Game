#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Character.h"
/// <summary>
/// Mage is the fastest hero. Mage have heal ability and huge dmg. 
/// </summary>
class Mage :public Character
{
public:
	Mage();
	//heal
	void ability(bool& threadFree) override;
private:
	void initVariables() override;
	void initTexture() override;
	void initSprite() override;
};

