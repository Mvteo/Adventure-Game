#include "pch.h"
#include "Enemy.h"
#include "collision.h"
#include "Player.h"
#include <iostream>
#include <cmath>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount,sf::Vector2f position, float switchTime,  int width, int height, float speed, float hp,float attack) :
	animation(texture, imageCount, switchTime, width, height)
{

	licznikPrzeciwnikow += 1;
	this->position = position;
	this->speed = speed;
	this->HP = hp;
	this->ATK =attack;
	this->counter = 0;
	this->player = player;
	this->atak = attack;
	row = 0;
	faceRight = true;
	body.setOrigin(sf::Vector2f(512.0f, 512.0f));
	body.setPosition(position);
	body.setTexture(*texture);
	counter2 = 0;
}

Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{
	
	velocity.x = 0.0f;

	counter++;
	counter2++;
	
	

	if (body.getPosition().x < this->position.x + 200 && counter < 4000) {
		velocity.x += speed;
	}
	else if (body.getPosition().x > this->position.x + 1 && counter > 4000) {
		velocity.x -= speed;
	}
	else if (counter > 8000)
		counter = 0;
		

	if (this->HP <= 0)
	{
		body.setPosition(-100.0f, -100.0f);
		this->HP = 2;
		Enemy::licznikPrzeciwnikow -= 1;
	}
	
	velocity.y += 0.0f;

	if (velocity.x == 0.0f)
	{
		row = 0;
	}

	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

float Enemy::getHP()
{
	return this->HP;
}

float Enemy::getATK()
{
	return this->ATK;
}

void Enemy::dealDMG(int DMG)
{
	this->HP -= DMG;
}

sf::Sprite Enemy::getSprite()
{
	return this->body;
}
