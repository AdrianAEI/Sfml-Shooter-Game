#include "Werewolf.h"
void Werewolf::initTexture()
{
	if (!this->texture.loadFromFile("Textures/werewolf.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Werewolf::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.55f, 0.55f);
	this->sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}

void Werewolf::initVariables()
{
	this->timer = 0;
	this->speed = 0.5f;
	this->type = 1;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->damage = 14;
	this->points = 5;
}

Werewolf::Werewolf(float posx, float posy)
{
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->sprite.setPosition(posx, posy);
}