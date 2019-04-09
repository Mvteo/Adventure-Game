#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

/*!
*
* @brief Jest to klasa przeciwnika sluzy ona do tworzenia przeciwnikow
*
*/
class Enemy
{
public:
/*!
*
* @brief Jest to konstruktor klasy Enemy
*
*@param texture Jest to wskaznik na teksture sluzy on do pobierania tekstury
*@param imageCount jest to ilosc klatek w animacji
*@param position sa to koordynaty miejsca w ktorym pojawia sie przeciwnik
*@param switchTime licznik czasu po ktorym zmienia sie klatka animacji
*@param width szerokosc klatki animacji
*@param height wysokosc klatki animacji
*@param speed szybkosc z jaka porusza sie przeciwnik
*@param hp ilosc punktow zdrowia
*@param attack sila ataku
*/
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, sf::Vector2f position, float switchTime, int width, int height, float speed, float hp,float attack);
	~Enemy();

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

	static int licznikPrzeciwnikow;  ///zmienna statyczna sluzy to liczenia ilu zostalo stworzonych przeciwnikow
	 /*!
	 *
	 *@brief getter ilosci punktow zycie
	 *
	 *@return zwraca ilosc zycia danego przeciwnika
	 */
	float getHP();
	/*!
	*
	*@brief getter ilosci punktow ataku
	*
	*@return zwraca ilosc ataku danego przeciwnika
	*/
	float getATK();
	float odleglosc; ///zmienna sluzaca do przypisania odleglosci gracza od przeciwnika
	/*!
	*
	*@brief Metoda odbierajaca punkty zycia przeciwnika
	*
	*@param DMG ilosc pkt zycia ktora odbieramy danemu przeciwnikowi
	*/
	void dealDMG(int DMG);
	float atak; ///zmienna sily ataki 

	 /*!
	 *
	 *@brief metoda zwracajaca pozycje przecinika
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
	sf::Sprite body;  ///jest to sprite przeciwnika czyli bardziej rozbudowana zmienna texture
	sf::Vector2f velocity;  ///wektor ktory okresla kierunek ruchu przeciwnika
	bool faceRight;  /// zmienna sluzaca do okreslania kierunku poruszania sie przeciwnika
private:

	Animation animation;  /// obiekt klasy Animation sluzy do animowania przeciwnika
	sf::Vector2f position;  /// wektor posiadajacy koordynaty przeciwnika
	sf::Vector2f player;  /// wektor posiadajacykoordynaty gracza
	unsigned int row;  /// zmienna uzywana przy animacji
	float speed;  /// zmienna szybkosci poruszania sie przeciwnikow
	int counter;  /// licznik uzywany przy funkcji ataku przeciwnika
	int counter2;  /// licznik uzywany przy funkcji ataku gracza
	float HP;  /// ilosc punktow zdrowia
	float ATK; /// ilosc sily ataku

};

