#include "Coin.h"

void Coin::initTexture()
{
	if (!this->texture.loadFromFile("Textures/luna.png"))
	{
		std::cout << "Error" << std::endl;
	}
}

void Coin::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.2f, 0.2f);
}

Coin::Coin(float posx, float posy)
{
	this->initTexture();
	this->initSprite();
	this->sprite.setPosition(posx, posy);
}

//Accessors
const sf::FloatRect Coin::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Coin::getPos() const
{
	return this->sprite.getPosition();
}

void Coin::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
