#pragma once
#include <SFML/Graphics.hpp>
/*!
*
*@brief Klasa Animation uzywana jest do animowania ruchow gracza oraz przeciwnikow
*
*
*/
class Animation
{
public:
/*!
*
*@brief Konstruktor klasy Animation
*
*@param texture jest to wskaznik na zmienna biblioteki sfml ktora przechowuje teksture obiektu
*@param imageCount jest to ilosc klatek animacji danej czynnosci 
*@param switchTime jest to czas po ktorym animacja zmienia klatke
*@param width jest to szerokosc klatki pobieranej z textury 
*@param height jest to height klatki pobieranej z textury 
*/
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, int width, int height);
	~Animation();

/*!
*
*@brief funkcja update pozwala na zmiane animacji ruchow
*
*@param row w tekstorze kazda czynnosc jest w osobnym rzedzie dzieki row wybieramy ktora animacja ma byc wyswietlana
*@param deltaTime jest to czas po ktorym nastepuje zmiana klatki animacji
*@param faceRight zmienna uzywana przy animacji ruchow w prawo i w lewo
*/
	void Update(int row, float deltaTime,bool faceRigt);

	sf::IntRect uvRect; /*!< Zmienna biblioteki SFML sluzy do ustawien parametrow klatki animacji */	
private:
	sf::Vector2u imageCount; /*!< Licznik klatek animacji */
	sf::Vector2u currentImage; ///Wskaznik na obecna klatke

	float totalTime; ///Licznik czasu
	float switchTime; ///Ilosc czasu po ktorym nastepuje zmiana klatki
};

