#include "pch.h"
#include "Animation.h"


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,int width,int height)
{
	
	this->imageCount = imageCount;
	this->switchTime = switchTime/2;
	totalTime = 0.0f;
	currentImage.x = 0;


	uvRect.width =width;
	uvRect.height = height;
}


Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRigt)
{
	
	totalTime += deltaTime;


	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if (faceRigt)
	{
		currentImage.y = row;
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}

	else
	{
		currentImage.y = row + 4;
		uvRect.left = (currentImage.x) * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
}
