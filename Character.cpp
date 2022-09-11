#include "Character.h"
void Character::move(const float DirX, const float DirY)
{
	this->sprite.move(this->movementSpeed * DirX, this->movementSpeed * DirY);
}
//character globalbounds
const sf::FloatRect Character::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const bool Character::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownmax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

const sf::Vector2f& Character::getPos() const
{
	return this->sprite.getPosition();
}

const int& Character::getHp() const
{
	return this->hp;
}

const int& Character::getHpMax() const
{
	return this->hpMax;
}

void Character::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Character::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Character::setHp(const int hp)
{
	this->hp = hp;
}

void Character::loseHp(const int value)
{
	this->hp -=value;
	if (this->hp < 0)
		this->hp = 0;
}

void Character::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownmax)
		attackCooldown += 0.5f;
}

void Character::update()
{
	this->updateAttack();
}

void Character::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

int Character::getDmg()
{
	return this->dmg;
}
