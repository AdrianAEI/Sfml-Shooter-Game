#include "Ghul.h"

void Ghul::initTexture()
{
	if (!this->texture.loadFromFile("Textures/ghulRemoved.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Ghul::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.25f, 0.25f);
	this->sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Ghul::initVariables()
{
	this->timer = 0;
	this->speed = 2.5f;
	this->type = 2;
	this->hpMax = 15;
	this->hp = this->hpMax;
	this->damage = 2;
	this->points = 5;
}

Ghul::Ghul(float posx, float posy)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(posx, posy);
}