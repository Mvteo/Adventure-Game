#pragma once
#include <SFML/Graphics.hpp>

/*!
*
*@brief maksymalna liczba elementow opcji
*/
#define MAX_NUMBER_OF_ITEMS 4

/*!
*
*@brief Klasa okna opcji
*
*/
class Opcje
{
public:
	/*!
	*
	*@brief konstruktor klasy opcje
	*
	*@param width szerokosc okna uzywana przy wyswietlaniu
	*@param height wysokosc okna uzywana przy wyswietlaniu
	*/
	Opcje(float width, float height);
	~Opcje();

	/*!
	*
	*@brief metoda rysujaca obiekt w podanym oknie
	*
	*@param window wskaznik na okno
	*/
	void draw(sf::RenderWindow &window);
	/*!
	*
	*@brieg metoda sluzaca do przelaczania sie miedzy opcjami w menu
	*
	*/
	void MoveUp();
	/*!
	*
	*@brief metoda sluzaca do przelaczania sie miedzy opcjami w menu
	*
	*/
	void MoveDown();
	/*!
	*
	*@brief metoda zwracajaca ktora opcja zostala wybrana
	*
	*@return wkasnik na wybrana opcje
	*/
	int GetPressedItem();

private:
	int selectedItemIndex; ///wkasnik na wybrana opcje
	sf::Font font; ///wskaznik na czcionke 
	sf::Text opcje[MAX_NUMBER_OF_ITEMS]; ///tablica mozliwych opcji

};
