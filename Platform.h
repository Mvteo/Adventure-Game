#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

/*!
*
*@brief Klasa z ktorej tworzone sa platformu
*
*/
class Platform
{
public:
	/*!
	*
	*@brief Konstruktor klasy platform
	*
	*@param texture wskaznik na teksture platformy
	*@param position miejsce w ktorym ma byc stworzona platforma
	*/
	Platform(sf::Texture* texture, sf::Vector2f position);
	~Platform();
	/*!
	*
	*@brief metoda rysujaca dana platforme
	*
	*@param window wskaznik na okno
	*/
	void Draw(sf::RenderWindow& window);
	/*!
	*
	*@brief zwraca wskaznik na sprite platformy
	*
	*@return wskaznik na sprite platformy
	*/
	sf::Sprite getSprite();
private:
	sf::Sprite body;  ///Sprite platformy
};

