#include "Drowner.h"


void Drowner::initTexture()
{
	if (!this->texture.loadFromFile("Textures/utopiec.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Drowner::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.25f, 0.25f);
	this->sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Drowner::initVariables()
{
	this->timer = 0;
	this->speed = 1.2f;
	this->type = 1;
	this->hpMax = 30;
	this->hp = this->hpMax;
	this->damage = 5;
	this->points = 5;
}

Drowner::Drowner(float posx, float posy)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(posx, posy);
}