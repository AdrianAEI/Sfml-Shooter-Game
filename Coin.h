#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/// <summary>
/// Object that player can collect
/// </summary>
class Coin
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	void initTexture();
	void initSprite();
public:
	Coin(float posx, float posy);
	//Accesors
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	//Render
	void render(sf::RenderTarget* target);
};

