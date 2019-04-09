#include "pch.h"
#include "Opcje.h"



Opcje::Opcje(float width, float height)
{
	font.loadFromFile("FONT.ttf");

	opcje[0].setFont(font);
	opcje[0].setFillColor(sf::Color::Red);
	opcje[0].setString("Latwy");
	opcje[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	opcje[1].setFont(font);
	opcje[1].setFillColor(sf::Color::White);
	opcje[1].setString("Sredni");
	opcje[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	opcje[2].setFont(font);
	opcje[2].setFillColor(sf::Color::White);
	opcje[2].setString("Trudny");
	opcje[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	opcje[3].setFont(font);
	opcje[3].setFillColor(sf::Color::White);
	opcje[3].setString("Wyjscie");
	opcje[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
}

Opcje::~Opcje()
{
}

int Opcje::GetPressedItem() {
	return selectedItemIndex;
}

void Opcje::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		window.draw(opcje[i]);
}

void Opcje::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		opcje[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		opcje[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Opcje::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		opcje[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		opcje[selectedItemIndex].setFillColor(sf::Color::Red);
	}

}
