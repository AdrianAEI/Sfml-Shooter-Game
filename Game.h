#pragma once
//includes
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Menu.h"
#include "Coin.h"
#include "Scoreboard.h"
#include "Ghul.h"
#include "Drowner.h"
#include "Werewolf.h"
#include "TextBox.h"
#include "Music.h"
#include <string>
#include <sstream>
#include <math.h>
#include<map>
#include<vector>
#include<thread>
#include<chrono>
#include <SFML/Audio.hpp>
/// <summary>
/// Heart of game, everything is cordinate here 
/// </summary>
class Game
{
private:
	//aim
	sf::Texture curText;
	sf::Sprite curSprite;
	//thread
	bool threadFree;
	std::jthread t1;
	//abilities
	sf::Texture aText;
	sf::Texture cdText;
	sf::Sprite aSprite;
	sf::Sprite cdSprite;
	//music
	Music music;
	//TextBox
	Textbox TextBox;
	std::string nick="";
	sf::Text invalidNIck;
	sf::RectangleShape rectangleShape;
	//states
	bool gameState = false;
	bool menuState = false;
	bool choiceState = false;
	bool scoreboardState = false;
	bool gameoverState = false;
	//scoreboard
	Scoreboard scoreBoard;
	//window
	sf::RenderWindow* window;
	//character
	Character* character = nullptr;
	//enemies
	std::vector<Enemy*> enemies;
	Enemy* enemy;
	float increaseSpawn;
	float spawnTimer;
	float spawnTimerMax;
	float enemyPosX;
	float enemyPosY;
	//coins
	Coin* coin;
	std::vector<Coin*> coins;
	float coinTimer;
	float coinTimerMax;
	//gui
	sf::Font font;
	sf::Text pointText;
	sf::Text gameOverText;
	//player Gui
	sf::RectangleShape characterHpBar;
	sf::RectangleShape characterHpBarBack;
	//background
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	//systems
	unsigned points;
	unsigned tempPoints;
	//shooting towards the mouse 
	sf::Vector2f MousePositionWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	sf::Vector2f enemyDir;
	sf::Vector2f enemyDirNorm;
	//bullets and bullets textures
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets; 
	//menu
	Menu menu;
	//inits
	void initWindow();
	void initCharacter(int HeroChoice);
	void initTextures();
	void initEnemies();
	void initCoins();
	void initWorld();
	void initGui();
	void initSystems();
	void initBox();
	void initScoreboard();
	void initAbilities();
	//for random enemy spawn
	int initRandom();
public:
	Game();
	virtual ~Game();
	//functions
	void run();
	void updatePollEvent();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void updateCoins();
	void updateCombat();
	void updateGui();
	void updateCollision();
	void update();
	void updateGame();
	void updateCursor();
	void render();
	void renderGame();
	void renderWorld();
	void renderGui();
	void renderGameover();
	void renderCursor();
	void updateMenu();
	void updateChoice();
	void renderMenu();
	//box
	void renderBox();
	//scoreboard
	void updateScoreboard();
	//Enemy cant spawn at player
	bool enemyCheckPos(float posx,float posy);
	bool enemyCheckPosWithEnemies(float posx, float posy);
	//To destroy objects after each game
	void objectsDestructor();
	// More enemy spawns during the game
	bool moreEnemy();
};

