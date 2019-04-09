#pragma once
#include <SFML/Graphics.hpp>

/*!
*
*@brief maksymalna liczba elementow menu
*/
#define MAX_NUMBER_OF_ITEMS 3

/*!
*
*@brief Klasa okna menu
*
*/
class Menu
{
public:
	/*!
	*
	*@brief konstruktor klasy menu
	*
	*@param width szerokosc okna uzywana przy wyswietlaniu
	*@param height wysokosc okna uzywana przy wyswietlaniu
	*/
	Menu(float width, float height);
	~Menu();

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
	sf::Text menu[MAX_NUMBER_OF_ITEMS]; ///tablica mozliwych opcji 
};

