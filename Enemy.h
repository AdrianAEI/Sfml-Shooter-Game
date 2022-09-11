#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/// <summary>
/// The represent of enemy
/// </summary>
class Enemy
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	//timer to rotate sprite every 10 frames
	int timer;
	float speed;
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;
	virtual void initVariables() = 0;
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
public:
	virtual void update(sf::Vector2f& dir);
	//Accesors
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPos() const;
	const int& getDamage() const;
	//functions
	void render(sf::RenderTarget* target);
	//geters seters
	int getHp();
	int getHpMax();
	void setHp(int how);
};

