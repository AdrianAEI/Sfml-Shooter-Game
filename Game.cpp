#include "Game.h"

//const
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initWorld();
	this->initCoins();
	this->initEnemies();
	this->initGui();
	this->initSystems();
	this->initBox();
	this->initScoreboard();
	this->initAbilities();
	menu.initMenu(this->window);
	this->menuState = true;
}

//dest
Game::~Game()
{
	delete this->window;
	for (auto& i : this->textures)
	{
		delete i.second; 
	}
	this->objectsDestructor();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080),"Wicher Dungeon",sf::Style::Fullscreen); 
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
	this->window->setMouseCursorVisible(false);
}
void Game::initGui()
{
	if (!this->font.loadFromFile("Fonts/arial.ttf"))
		std::cout << "Failed load font" << std::endl;
	this->pointText.setPosition(20, 50);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(40);
	this->pointText.setFillColor(sf::Color::Green);
	this->pointText.setString("points");
	//invalid nick text
	this->invalidNIck.setPosition(this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f-700,
	this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f-300);
	this->invalidNIck.setFont(this->font);
	this->invalidNIck.setCharacterSize(40);
	this->invalidNIck.setFillColor(sf::Color::Red);
	this->invalidNIck.setString("Enter your nickname, up to 10 characters, without space or special characters!");
	//game over text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over");
	this->gameOverText.setPosition(this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f - 400);
	//player hp bar
	this->characterHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->characterHpBar.setFillColor(sf::Color::Red);
	this->characterHpBar.setPosition(20.f, 20.f);

	this->characterHpBarBack = this->characterHpBar;
	this->characterHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	//mouse cursor
	curText.loadFromFile("Textures/celownik.png");
	curSprite.setTexture(curText);
	curSprite.setScale(0.2f, 0.2f);
	curSprite.setOrigin(curSprite.getGlobalBounds().height / 2, curSprite.getGlobalBounds().width / 2);
		
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Textures/dungeonBackground.png"))
	{
		std::cout << "Error with load world" << std::endl;
	};
	this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initCharacter(int HeroChoice)
{
	if (HeroChoice == 1)
	{
		this->character = new Warrior();
		this->textures["BULLET"]->loadFromFile("Textures/swordRemoved.png");
	}
	else if (HeroChoice == 2)
	{
		this->character = new Ranger();
		this->textures["BULLET"]->loadFromFile("Textures/shuriken.png");
	}
		
	else if (HeroChoice == 3)
	{
		this->character = new Mage();
		this->textures["BULLET"]->loadFromFile("Textures/fireballRemoved.png");
	}

}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
}
void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}
void Game::initCoins()
{
	this->coinTimerMax = 100.f;
	this->coinTimer = this->coinTimerMax;
}
void Game::initBox()
{
	rectangleShape.setSize(sf::Vector2f(400.f, 50.f));
	rectangleShape.setFillColor(sf::Color::White);
	rectangleShape.setPosition(this->window->getSize().x/2-200.f, this->window->getSize().y / 2-150.f);
	TextBox.setTextbox(30, sf::Color::Red, true, font, { this->window->getSize().x / 2-200.f,this->window->getSize().y / 2-150.f });
}

void Game::initScoreboard()
{
	scoreBoard.loadFromFile();
	scoreBoard.seeScoreboard();
}

void Game::initSystems()
{
	music.play(1);
	this->points = 0;
	this->tempPoints = 0;
	this->increaseSpawn = 0.5f;
	this->threadFree = true;
}

int Game::initRandom()
{
	return rand() % 5 + 1;
}

void Game::initAbilities()
{
	aText.loadFromFile("Textures/ability.png");
	aSprite.setTexture(aText);
	aSprite.setScale(0.5f, 0.5f);
	aSprite.setPosition(20.f, 100.f);
	cdText.loadFromFile("Textures/cdability.png");
	cdSprite.setTexture(cdText);
	cdSprite.setScale(0.5f, 0.5f);
	cdSprite.setPosition(20.f, 100.f);
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		this->render();
	}
}

void Game::updateGame()
{
	this->updateInput();
	this->character->update();
	this->updateCollision();
	this->updateBullets();
	this->updateEnemies();
	this->updateCoins();
	this->updateCombat();
	this->updateGui();
	this->updateCursor();
	//Game over screen
	if (this->character->getHp() <= 0)
	{
		gameoverState = true;
		gameState = false;
	}
}
void Game::updateCursor()
{
	curSprite.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}
//render all
void Game::render()
{
	this->window->clear();

	if (this->gameState)
	{
		this->renderGame();
	}
	if (this->menuState)
	{
		this->renderMenu();
	}
	if (this->choiceState)
	{
		this->renderMenu();
	}
	if (this->scoreboardState)
	{
		scoreBoard.renderScoreboard(this->window);
	}
	if (this->gameoverState)
	{
		this->renderGameover();
	}

	this->window->display();
}
void Game::renderGame()
{
	//coins render
	this->renderWorld();
	for (auto* coin : this->coins)
	{
		coin->render(this->window);
	}
	//character render
	this->character->render(*this->window);
	//bullets render
	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}
	//enemy render
	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}
	//render hp, cursor
	this->renderGui();
	this->renderCursor();
	//render ability cd
	if (this->threadFree)
		this->window->draw(aSprite);
	else
		this->window->draw(cdSprite);
}

void Game::updateCoins()
{
	this->coinTimer += 0.5f;
	if (this->coinTimer >= this->coinTimerMax)
	{
		this->coins.push_back(new Coin(rand() % this->window->getSize().x, rand()% this->window->getSize().y));
		this->coinTimer = 0.f;
	}
	unsigned counter = 0;
	for (auto* coin : this->coins)
	{
		//Colect coin
		if (coin->getBounds().intersects(this->character->getBounds()))
		{
			delete this->coins.at(counter);
			this->coins.erase(this->coins.begin() + counter);
			points += 50;
			--counter;
		}
		//no coins on edges
		else if (coin->getPos().y + coin->getBounds().height > this->window->getSize().y ||
			coin->getPos().y  < 0.f ||
			coin->getPos().x + coin->getBounds().width > this->window->getSize().x ||
			coin->getPos().x < 0.f
			)
			{
				delete this->coins.at(counter);
				this->coins.erase(this->coins.begin() + counter);
				--counter;
			}
		++counter;
	}
}

void Game::renderMenu()
{
	menu.RenderWindow();
}

void Game::renderBox()
{
	window->draw(rectangleShape);
	TextBox.draw(this->window);
}

void Game::updateEnemies()
{
	this->spawnTimer += increaseSpawn;
	if (moreEnemy())
		increaseSpawn += 0.1f;

	
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemyPosX = rand() % this->window->getSize().x - 20.f;
		this->enemyPosY = rand() % this->window->getSize().y - 20.f;
		if (enemyCheckPos(this->enemyPosX, this->enemyPosY) && enemyCheckPosWithEnemies(this->enemyPosX, this->enemyPosY))
		{
			int random = initRandom();
			if (random == 1 || random == 2)
			{
				this->enemies.push_back(new Drowner(this->enemyPosX, this->enemyPosY));
			}
			else if (random == 3 || random == 4)
			{
				this->enemies.push_back(new Ghul(this->enemyPosX, this->enemyPosY));
			}
			else if(random==5)
			{
				this->enemies.push_back(new Werewolf(this->enemyPosX, this->enemyPosY));
			}
			this->spawnTimer = 0.f;
		}
	}
	//collision
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemyDir = this->character->getPos() - enemy->getPos();
		enemyDirNorm = sf::Vector2f(enemyDir.x / sqrt(pow(enemyDir.x, 2) + pow(enemyDir.y, 2)), enemyDir.y / sqrt(pow(enemyDir.x, 2) + pow(enemyDir.y, 2)));
			enemy->update(enemyDirNorm);
		//Enemy culling
		if (enemy->getPos().y + enemy->getBounds().height > this->window->getSize().y ||
			enemy->getPos().y < 0.f ||
			enemy->getPos().x + enemy->getBounds().width > this->window->getSize().x ||
			enemy->getPos().x < 0.f)
			{
			//Delete enemy
				delete this->enemies.at(counter);
				this->enemies.erase(this->enemies.begin() + counter);
				--counter;
			}
		//enemy colission with player
		else if(enemy->getBounds().intersects(this->character->getBounds()))
		{
			//Delete enemy
			this->character->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}

		++counter;
	}
}
void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_removed = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_removed==false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				enemies[i]->setHp(this->character->getDmg());
				if (enemies[i]->getHp() <= 1)
                {
					//delete enemy
                    this->points += this->enemies[i]->getHpMax()/5;
                    this->tempPoints++;
					delete this->enemies[i];
                    this->enemies.erase(enemies.begin() + i);
					enemy_removed = true;
                }

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				
			}
		}

	}
}
void Game::updateGui()
{
	std::stringstream ss;
	ss <<"Points: "<< this->points;
	this->pointText.setString(ss.str());

	//update player gui HP BAR
	float hpPercent = static_cast<float>(this->character->getHp()) / this->character->getHpMax(); //static cast needed
	this->characterHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->characterHpBar.getSize().y));
}

//draw hp itp
void Game::renderGui()
{
	this->window->draw(this->pointText);
	this->window->draw(this->characterHpBarBack);
	this->window->draw(this->characterHpBar);
}

void Game::renderGameover()
{
	this->window->draw(worldBackground);
	this->window->draw(gameOverText);
	this->window->draw(invalidNIck);
	renderBox();
	if (nick != "")
	{
		if (scoreBoard.correctNick(nick))
		{
			scoreBoard.saveToFile(nick, this->points);
			this->initScoreboard();
			menu.initMenu(this->window);
			this->points = 0;
			this->tempPoints = 0;
			this->increaseSpawn = 0.5f;
			gameoverState = false;
			menuState = true;
			music.stop(2);
			music.play(1);
			this->invalidNIck.setString("Enter your nickname, up to 10 characters, without space or special characters!");
			this->objectsDestructor();			
		}
		else
		{
			this->invalidNIck.setString(nick + " is invalid! Try again!");
		}
		this->nick = "";
	}
}

void Game::renderCursor()
{
	this->window->draw(this->curSprite);
}

void Game::updateCollision()
{
	if (this->character->getBounds().left < 0.f)
	{
		this->character->setPosition(0.f, this->character->getBounds().top);
	}
	else if (this->character->getBounds().left+this->character->getBounds().width >= this->window->getSize().x)
	{
		this->character->setPosition(this->window->getSize().x- this->character->getBounds().width, this->character->getBounds().top);
	}
	if (this->character->getBounds().top < 0.f)
	{
		this->character->setPosition(this->character->getBounds().left, 0.f);
	}
	else if (this->character->getBounds().top+ this->character->getBounds().height >= this->window->getSize().y)
	{
		this->character->setPosition(this->character->getBounds().left,this->window->getSize().y-this->character->getBounds().height);
	}
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::updatePollEvent()
{
	if (this->gameState)
		this->updateGame();
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			this->window->close();
		if (this->gameoverState)
		{
			if (e.type == sf::Event::TextEntered && this->character->getHp() <= 0)
			{
				TextBox.update(e, nick);
			}
		}
		if (this->choiceState)
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressed())
					{
					case 0:
						choiceState = false;
						this->initCharacter(1);
						gameState = true;
						break;
					case 1:
						choiceState = false;
						this->initCharacter(2);
						gameState = true;
						break;
					case 2:
						choiceState = false;
						this->initCharacter(3);
						gameState = true;
						break;
					}
					music.stop(1);
					music.play(2);
					break;
				}
				break;
			}
		}

		if (this->menuState)
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressed())
					{
					case 0:
						menuState = false;
						menu.initChoice();
						choiceState = true;
						break;
					case 1:
						menuState = false;
						scoreboardState = true;
						break;
					case 2:
						window->close();
						break;
					}
					break;
				}
				break;
			}
		}
		if (this->scoreboardState)
		{
			if (e.Event::type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				this->scoreboardState = false;
				this->menuState = true;
			}
		}
	}

}
//<thread>
void Game::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->character->move(-1.0f, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->character->move(1.0f, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->character->move(0, 1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->character->move(0, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)&&this->points>=50&& threadFree)//ability 
	{
			threadFree = false;
			t1=std::jthread(&Character::ability,character,std::ref(threadFree));
			t1.detach();
			this->points -= 50;
	}

	//create bullet
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&this->character->canAttack())
	{
		MousePositionWindow = sf::Vector2f(sf::Mouse::getPosition(*window));
		aimDir = MousePositionWindow - this->character->getPos();
		aimDirNorm = sf::Vector2f(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)), aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
		this->bullets.push_back(new Bullet(this->textures["BULLET"],this->character->getPos().x+50.f, this->character->getPos().y+45.f, aimDirNorm, 5.f));
	}
}

void Game::updateBullets()
{
	unsigned counter=0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//Bullet culling
		if (bullet->getPos().y +bullet->getBounds().height > this->window->getSize().y + 25.f ||
			bullet->getPos().y  < 0.f||
			bullet->getPos().x + bullet->getBounds().width > this->window->getSize().x + 25.f ||
			bullet->getPos().x < 0.f
			)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

bool Game::enemyCheckPos(float posx, float posy)
{
	if (abs(posx - this->character->getPos().x) > 100 && abs(posy - this->character->getPos().y) > 100)
		return true;
	else
		return false;
}

bool Game::enemyCheckPosWithEnemies(float posx, float posy)
{
	for (auto* i : this->enemies)
	{
		if (abs(posx - i->getPos().x) > 10 && abs(posy - i->getPos().y) > 10)
			return true;
		else
			return false;
	}
	return true;
}

void Game::objectsDestructor()
{

	for (auto* i : this->enemies)
	{
		delete i;
	}
	for (auto* i : this->coins)
	{
		delete i;
	}
	for (auto* i : this->bullets)
	{
		delete i;
	}
	
	this->enemies.clear(); //vector size=0
	this->coins.clear();
	this->bullets.clear();
	delete this->character;
	this->character = nullptr;
}
//increase spawn
bool Game::moreEnemy()
{

	if (tempPoints >= 5)
	{	
		tempPoints = 0;
		return true;
	}
	else
	{
		return false;
	}	
}
