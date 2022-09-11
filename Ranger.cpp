#include "Ranger.h"
Ranger::Ranger()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}
void Ranger::initVariables()
{
	this->movementSpeed = 7.5f;
	this->attackCooldownmax = 10.f;
	this->attackCooldown = this->attackCooldownmax;
	this->hpMax = 15;
	this->hp = this->hpMax;
	this->dmg = 15;
}
void Ranger::initTexture()
{
	if (!this->texture.loadFromFile("Textures/rangerRemoved.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Ranger::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(300.f, 300.f);
}

void Ranger::ability(bool& threadFree)
{
	this->dmg += 5;
	this->movementSpeed += 2.5f;
	this->attackCooldownmax -= 5.f;
	//wait 5s
	std::this_thread::sleep_for(std::chrono::seconds(5));
	this->dmg -= 5;
	this->movementSpeed -= 2.5f;
	this->attackCooldownmax += 5.f;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	threadFree = true;
}