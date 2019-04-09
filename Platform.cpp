#include "pch.h"
#include "Platform.h"
#include "collision.h"
#include "Player.h"


Platform::Platform(sf::Texture* texture, sf::Vector2f position)
{
	
	body.setOrigin(45,45);
	body.setTexture(*texture);
	body.setPosition(position);

}


Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

sf::Sprite Platform::getSprite()
{
	return body;
}
