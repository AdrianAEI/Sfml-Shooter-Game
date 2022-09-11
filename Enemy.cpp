#include "Enemy.h"

const sf::FloatRect Enemy::getBounds() const 
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Enemy::getPos() const
{
	return this->sprite.getPosition();
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

void Enemy::update(sf::Vector2f &dir)
{
	this->sprite.move(dir*this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	 timer++;
	 if (timer == 10)
	 {
		 this->sprite.rotate(-4.f);
		 
	 }
	 else if (timer == 20)
	 {
		 this->sprite.rotate(4.f);
		 timer = 0;
	 }
	
	target->draw(this->sprite);
}

int Enemy::getHp()
{
	return this->hp;
}

int Enemy::getHpMax()
{
	return this->hpMax;
}

void Enemy::setHp(int how)
{
	this->hp -= how;
}
