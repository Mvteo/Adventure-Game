#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
/*!
*
*@brief Jest to klasa gracza
*/
class Player
{
public:
/*!
*
* @brief Jest to konstruktor klasy Player
*
*@param texture Jest to wskaznik na teksture sluzy on do pobierania tekstury
*@param imageCount jest to ilosc klatek w animacji
*@param switchTime licznik czasu po ktorym zmienia sie klatka animacji
*@param speed szybkosc z jaka porusza sie przeciwnik
*@param jumpHeight wysokosc skoku
*@param width szerokosc klatki animacji
*@param height wysokosc klatki animacji
*/
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int width, int height);
	~Player();

	/*!
	*
	*@brief metoda sluzaca do aktualizowania klatek animacji w danym momencie
	*
	*@param deltaTime jednostka czasu
	*/
	void Update(float deltaTime);

	/*!
	*
	*@brief metoda rysujaca obiekt w podanym oknie
	*
	*@param window wskaznik na okno w ktorym ma byc rysowana teksture
	*/
	void Draw(sf::RenderWindow& window);


	/*!
	*
	*@brief getter ilosci punktow zycie
	*
	*@return zwraca ilosc zycia danego przeciwnika
	*/
	int getHP();

	/*!
	*
	*@brief setter ilosci punktow ataku
	*
	*@param HP ilosc zycia ktora ustawiamy
	*/
	void setHP(int HP);

	/*!
	*
	*@brief getter ilosci punktow ataku
	*
	*@return zwraca ilosc ataku danego przeciwnika
	*/
	int getATK();

	/*!
	*
	*@brief setter ilosci punktow ataku
	*
	*@param ATK ilosc ataku ktora ustawiamy
	*/
	void setATK(int ATK);

	/*!
	*
	*@brief metoda zwracajaca pozycje gracza
	*
	*@return zwraca pozycje
	*/
	sf::Vector2f GetPosition() { return body.getPosition(); };


	/*!
	*
	*@brief getter wskaznika na sprita
	*
	*@return zwraca wskaznik na sprita
	*/
	sf::Sprite getSprite();


	sf::Sprite body; ///sprite gracza
	sf::Vector2f velocity;  ///zmienna ustalajaca kierunek poruszania sie gracza


	/*!
	*
	*@brief metoda zadajaca obrazenia graczowi
	*
	*@param DMG ilosc zadawanych punktow obrazen
	*/
	void dealDMG(int DMG);
	bool canJump; ///zmienna pozwalajaca skakac graczowi 
	bool canDMG; ///zmienna pozwalajaca otrzymywac obrazenia przez gracza 
	bool faceRight; ///zmienna uzywana przy ustalanie kierunku poruszania sie gracza 
private:

	Animation animation; ///Obiekt klasy animation uzywany przy animowaniu ruchow gracza 
	
	unsigned int row; ///wskaznik na rzad w teksturze gracza 
	float speed; ///szybkosc poruszania sie gracza 
	float totalTime; ///licznik czasu 
	float counter; ///licznik uzywany przy funkcji ataku przeciwnika 
	int HP; ///ilosc pkt zdrowia 
	int ATK; ///sila ataku 


	float jumpHeight; ///wysokosc skoku gracza
};

