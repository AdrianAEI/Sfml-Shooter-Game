#include "Bullet.h"
Bullet::Bullet() {}
Bullet::Bullet(sf::Texture* texture,float posX, float posY, sf::Vector2f dir, float movSpeed)
{
	this->sprite.setTexture(*texture);
	this->sprite.setScale(0.15f, 0.15f);
	this->sprite.setPosition(posX, posY);
	this->sprite.setOrigin(texture->getSize().x / static_cast<float>(2), texture->getSize().y / static_cast<float>(2));
	this->direction = dir;
	this->movementSpeed = movSpeed;
}
const sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
//Movements
void Bullet::update()
{
	this->sprite.move(this->movementSpeed * this->direction);
	this->sprite.rotate(3.f);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

const sf::Vector2f& Bullet::getPos() const
{
	return this->sprite.getPosition();
}
