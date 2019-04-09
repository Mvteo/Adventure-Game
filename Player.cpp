#include "pch.h"
#include "Player.h"
#include "collision.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int width, int height):
	animation(texture, imageCount,switchTime, width, height)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setOrigin(sf::Vector2f(256.0f, 256.0f));
	body.setPosition(300.0f, 1443.0f);
	body.setTexture(*texture);
	 this->HP = 200;
	 this->ATK = 10;
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;

		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;


	if (velocity.x == 0.0f)
	{
		row = 3;
	}

	else
	{
		row = 0;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
		
	}

	if (velocity.y < 0.0f)
	{
		row = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		row = 1;
	}



	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

int Player::getHP()
{
	return this->HP;
}

void Player::setHP(int HP) {
	this->HP = HP;
}

int Player::getATK()
{
	return this->ATK;
}

void Player::setATK(int ATK) {
	this->ATK = ATK;
}

sf::Sprite Player::getSprite()
{
	return this->body;
}

void Player::dealDMG(int DMG)
{
	if(canDMG=true)
	this->HP -=DMG;
	//canDMG = false;
}

