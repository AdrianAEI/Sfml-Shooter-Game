#include "Mage.h"
Mage::Mage()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}
void Mage::ability(bool& threadFree)
{	
	this->hp = hpMax;
	std::this_thread::sleep_for(std::chrono::seconds(10));
	threadFree = true;
}
void Mage::initVariables()
{
	this->movementSpeed = 10.f;
	this->attackCooldownmax = 10.f;
	this->attackCooldown = this->attackCooldownmax;
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->dmg = 20;
}
void Mage::initTexture()
{
	if (!this->texture.loadFromFile("Textures/SpriteTriss.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Mage::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(300.f, 300.f);
}