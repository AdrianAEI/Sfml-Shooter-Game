#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/// <summary>
/// Typical Bullet. Hereos have different shooting
/// </summary>
class Bullet
{
private:
	sf::Texture text;
	sf::Sprite sprite;
	sf::Vector2f direction;
	float movementSpeed;
public:
	Bullet();
	//pos is a position of player
	Bullet(sf::Texture* texture,float posX,float posY,sf::Vector2f dir,float movSpeed);
	//Accesors
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	void update();
	void render(sf::RenderTarget* target);
};

