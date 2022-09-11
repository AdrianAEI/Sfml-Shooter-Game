#include "Warrior.h"
Warrior::Warrior()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();	
}
void Warrior::initVariables()
{
	this->movementSpeed = 5.f;
	this->attackCooldownmax = 10.f;
	this->attackCooldown = this->attackCooldownmax;
	this->hpMax = 20;
	this->hp = this->hpMax;
	this->dmg = 10;
}
void Warrior::initTexture()
{
	if (!this->texture.loadFromFile("Textures/geraltRemoved.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Warrior::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(300.f, 300.f);
}
void Warrior::ability(bool& threadFree)
{
	int tempHp = this->hp;
	this->hp =IMMORTAL;
	//wait 3s
	std::this_thread::sleep_for(std::chrono::seconds(3));
	this->hp = tempHp;
	std::this_thread::sleep_for(std::chrono::seconds(7));
	threadFree = true;
}