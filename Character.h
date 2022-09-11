#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <thread>
#include <chrono>
/// <summary>
/// It represents a player
/// </summary>
class Character
{
//must be protected
protected: 
	sf::Sprite sprite;
	sf::Texture texture;
	float attackCooldown;
	float attackCooldownmax;
	float movementSpeed;
	//hp dmg
	int hp;
	int hpMax;
	int dmg;
	//polymorphism
	virtual void initVariables()=0;
	virtual void initTexture()=0;
	virtual void initSprite()=0;	
public:
	virtual void ability(bool& threadFree) = 0;
	void move(const float DirX, const float DirY);
	//Accesors
	const sf::FloatRect getBounds() const;
	const bool canAttack();
	const sf::Vector2f& getPos() const;
	const int& getHp() const;
	const int& getHpMax() const;
	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x,const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
	int getDmg();
};

