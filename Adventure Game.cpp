#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include "Enemy.h"
#include "Menu.h"
#include "Opcje.h"
#include "collision.h"
static const float VIEW_HEIHGT = 512.0f;


/*!
*
*@brief funkcja ustawiajaca nowy widok (miejsce ktore jest aktualnie wyswietlane na ekranie)
*
*@param window wskaznik na okno
*@param view wskaznik na widok
*/
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_HEIHGT * aspectRatio, VIEW_HEIHGT);
}

/*!
*
*@brief funkcja uruchamiana po wygraniu gry. ustawia nowy widok i wypisuje informacje o wygraniej
*
*@param window wskaznik na okno
*@param font wskaznik na czcionke
*@param view wskaznik na widok
*/
void win(sf::RenderWindow& window, sf::Font font,sf::View& view) {
	window.clear();
	view.setCenter(500, 500);
	ResizeView(window, view);
	window.setView(view);
	std::string EndGame = ("You win!" );
	sf::Text text(EndGame, font, 50);
	text.setFillColor(sf::Color(155, 0, 0));
	text.setPosition(350,400);
	window.draw(text);
}

/*!
*
*@brief funkcja uruchamiana po przegraniu gry. Ustawia nowy widok i wypisuje informacje o przegranej
*
*@param window wskaznik na okno
*@param font wskaznik na czcionke
*@param view wskaznik na widok
*/
 void lose(sf::RenderWindow& window, sf::Font font,sf::View& view) {
	view.setCenter(500, 500);
	ResizeView(window, view);
	window.setView(view);
	std::string EndGame = ("GAME OVER!");
	sf::Text text(EndGame, font, 50);
	text.setFillColor(sf::Color(155, 0, 0));
	text.setPosition(350,400);
	window.clear();
	window.draw(text);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		window.close();
}

/*!
*
*@brief funkcja sluzaca do tworzenia duzej ilosci przeciwnikow
*
*@param gobliny wksanik na wektor obiektow
*@param golemE wksanik na wektor obiektow
*@param goblinTexture wkaznik na tekstore przeciwnikow
*
*/
void createMinions(std::vector<Enemy>& gobliny, std::vector<Enemy>& golemE,sf::Texture& goblinTexture, sf::Texture& golemTexture, sf::Texture& orkTexture, sf::Texture& iceTexture, sf::Texture& bossTexture){

	gobliny.push_back(Enemy(&goblinTexture, sf::Vector2u(4, 2), sf::Vector2f(680.0f, 1340.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));
	gobliny.push_back(Enemy(&goblinTexture, sf::Vector2u(4, 2), sf::Vector2f(1274.0f, 1290.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));
	gobliny.push_back(Enemy(&goblinTexture, sf::Vector2u(4, 2), sf::Vector2f(2577.0f, 1340.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));

	golemE.push_back(Enemy(&golemTexture, sf::Vector2u(4, 2), sf::Vector2f(850.0f, 1447.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));
	golemE.push_back(Enemy(&golemTexture, sf::Vector2u(4, 2), sf::Vector2f(1575.0f, 1277.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));
	golemE.push_back(Enemy(&golemTexture, sf::Vector2u(4, 2), sf::Vector2f(2500.0f, 1447.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));
	golemE.push_back(Enemy(&golemTexture, sf::Vector2u(4, 2), sf::Vector2f(3080.0f, 1277.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 50.0f, 10.0f));


}

/*!
*
*@brief funkcja sluzaca to dtorzenia duzej ilosci platform
*
*@param small wskaznik na wektor obiektow
*@param platformSmallTexture,platformSmallTextureIce,platformSmallTextureStone wskaznik na teksture malej platformy
*@param platformBigTexture,platformBigTextureIce,platformBigTextureStone wskaznik na teksture malej platformy
*/
void createPlatforms(std::vector<Platform>& small, std::vector<Platform>& smallIce, std::vector<Platform>& smallStone, std::vector<Platform>& big, std::vector<Platform>& bigIce, std::vector<Platform>& bigStone,
	sf::Texture& platformSmallTexture, sf::Texture& platformSmallTextureIce, sf::Texture& platformSmallTextureStone, sf::Texture& platformBigTexture, sf::Texture& platformBigTextureIce, sf::Texture& platformBigTextureStone ) {
	small.push_back(Platform(&platformSmallTexture, sf::Vector2f(1050.0f, 1200.0f)));
	small.push_back(Platform(&platformSmallTexture, sf::Vector2f(1800.0f, 1200.0f)));
	small.push_back(Platform(&platformSmallTexture, sf::Vector2f(2200.0f, 1200.0f)));
	//pierwsza mapa duze
	big.push_back(Platform(&platformBigTexture, sf::Vector2f(700.0f, 1350.0f)));
	big.push_back(Platform(&platformBigTexture, sf::Vector2f(1300.0f, 1300.0f)));
	big.push_back(Platform(&platformBigTexture, sf::Vector2f(1300.0f, 950.0f)));
	big.push_back(Platform(&platformBigTexture, sf::Vector2f(1900.0f, 1350.0f)));
	big.push_back(Platform(&platformBigTexture, sf::Vector2f(2600.0f, 1350.0f)));
	big.push_back(Platform(&platformBigTexture, sf::Vector2f(3100.0f, 1250.0f)));
	// druga mapa male
	smallIce.push_back(Platform(&platformSmallTextureIce, sf::Vector2f(700.0f, 1350.0f)));
	smallIce.push_back(Platform(&platformSmallTextureIce, sf::Vector2f(1050.0f, 1350.0f)));
	smallIce.push_back(Platform(&platformSmallTextureIce, sf::Vector2f(1300.0f, 1200.0f)));
	smallIce.push_back(Platform(&platformSmallTextureIce, sf::Vector2f(2850.0f, 1200.0f)));
	//druga mapa duze
	bigIce.push_back(Platform(&platformBigTextureIce, sf::Vector2f(1600.0f, 1300.0f)));
	bigIce.push_back(Platform(&platformBigTextureIce, sf::Vector2f(2000.0f, 1300.0f)));
	bigIce.push_back(Platform(&platformBigTextureIce, sf::Vector2f(2500.0f, 1300.0f)));
	bigIce.push_back(Platform(&platformBigTextureIce, sf::Vector2f(3100.0f, 1300.0f)));
	//trzecia mapa
	smallStone.push_back(Platform(&platformSmallTextureStone, sf::Vector2f(850.0f, 1300.0f)));
	smallStone.push_back(Platform(&platformSmallTextureStone, sf::Vector2f(1300.0f, 1300.0f)));
	//trzecia mapa
	bigStone.push_back(Platform(&platformBigTextureStone, sf::Vector2f(500.0f, 1350.0f)));
	bigStone.push_back(Platform(&platformBigTextureStone, sf::Vector2f(1700.0f, 1350.0f)));

}


int Enemy::licznikPrzeciwnikow = 0; /*!< zmienna statyczna uzywana do liczenia ilosci przeciwnikow */

/*!
*
*@brief funkcja main w ktorej dziala cala gra
*
*/
int main()
{
	
	int okno = 3;
	int counter = 0;
	float odleglosc;
	float lvl;

	sf::RenderWindow window(sf::VideoMode(1024,768), "Adventure Game",sf::Style::Close| sf::Style::Resize); /*!< zmienna okna w ktorym bedzie wyswietlana gra */
	Menu menu(window.getSize().x, window.getSize().y); /*!< Obiekt klasy Menu */
	Opcje opcje(window.getSize().x, window.getSize().y); /*!<Obiekt klasy Opcje */
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 346.0f)); /*!< Zmienna widoku */
	sf::Texture playerTexture; ///Tekstura gracza 
	sf::Texture goblinTexture;///Tekstura przeciwnika 
	sf::Texture orkTexture; ///Tekstura przeciwnika 
	sf::Texture golemTexture; ///Tekstura przeciwnika 
	sf::Texture iceTexture;///Tekstura przeciwnika 
	sf::Texture bossTexture;///Tekstura przeciwnika 
	sf::Texture backgroundTexture;///Tekstura tla 
	sf::Texture backgroundTextureIce; ///Tekstura tla 
	sf::Texture backgroundTextureStone; ///Tekstura tla 
	sf::Texture groundTexture; ///Tekstura podloza 
	sf::Texture groundTextureIce;  ///Tekstura podloza 
	sf::Texture groundTextureStone;  ///Tekstura podloza 
	sf::Texture platformSmallTexture;  ///Tekstura platformy 
	sf::Texture platformSmallTextureIce;  ///Tekstura platformy 
	sf::Texture platformSmallTextureStone;  ///Tekstura platformy 
	sf::Texture platformBigTexture;  ///Tekstura platformy 
	sf::Texture platformBigTextureIce;  ///Tekstura platformy 
	sf::Texture platformBigTextureStone;  ///Tekstura platformy 


	sf::Sprite backgroundSprite;
	sf::Sprite playerSprite;

	sf::Font font;
	font.loadFromFile("FONT.TTF");


	backgroundTexture.loadFromFile("background.png");
	backgroundTextureIce.loadFromFile("lodowa.png");
	backgroundTextureStone.loadFromFile("zlo.png");
	playerTexture.loadFromFile("TrueChampion.png");
	goblinTexture.loadFromFile("goblin.png");
	golemTexture.loadFromFile("golemE.png");
	iceTexture.loadFromFile("golemS.png");
	bossTexture.loadFromFile("golemB.png");
	orkTexture.loadFromFile("ork.png");
	groundTexture.loadFromFile("ziemia.png");
	groundTextureIce.loadFromFile("lod.png");
	groundTextureStone.loadFromFile("skala.png");
	platformSmallTexture.loadFromFile("platformSmall.png");
	platformSmallTextureIce.loadFromFile("platformSmallSnow.png");
	platformSmallTextureStone.loadFromFile("platformSmallStone.png");
	platformBigTexture.loadFromFile("platformBig.png");
	platformBigTextureIce.loadFromFile("platformBigSnow.png");
	platformBigTextureStone.loadFromFile("platformBigStone.png");

	Player player(&playerTexture, sf::Vector2u(4, 8), 0.15f, 300.0f, 200.0f, 2056 / 4.01, 4096 / 8);
	playerSprite.setTexture(playerTexture);
	backgroundSprite.setTexture(backgroundTexture);

	std::vector<Enemy>gobliny;
	std::vector<Enemy>golemE;

	Enemy ork1(&orkTexture, sf::Vector2u(4, 2), sf::Vector2f(3327.0f, 1430.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 200.0f, 20.0f);
	Enemy ice1(&iceTexture, sf::Vector2u(4, 2), sf::Vector2f(3327.0f, 1430.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 200.0f, 20.0f);
	Enemy boss(&bossTexture, sf::Vector2u(4, 2), sf::Vector2f(985.0f, 1425.0f), 0.15f, 3600 / 4, 2056 / 2.3, 150.0f, 200.0f, 20.0f);
	createMinions(gobliny, golemE, goblinTexture, golemTexture, orkTexture, iceTexture, bossTexture);
	

	backgroundSprite.setPosition(0.0f, -500.0f);
	backgroundSprite.setScale(sf::Vector2f(2.0f, 2.0f));

	Platform ground(&groundTexture, sf::Vector2f(45.0f, 1500.0f));
	Platform groundIce(&groundTextureIce, sf::Vector2f(45.0f, 1500.0f));
	Platform groundStone(&groundTextureStone, sf::Vector2f(45.0f, 1500.0f));
	Platform ground1(&groundTexture, sf::Vector2f(1920.0f, 1500.0f));
	Platform groundIce1(&groundTextureIce, sf::Vector2f(1920.0f, 1500.0f));
	Platform groundStone1(&groundTextureStone, sf::Vector2f(1920.0f, 1500.0f));

	std::vector<Platform>small;
	std::vector<Platform>smallIce;
	std::vector<Platform>smallStone;
	std::vector<Platform>big;
	std::vector<Platform>bigIce;
	std::vector<Platform>bigStone;

	
	createPlatforms(small, smallIce, smallStone, big, bigIce, bigStone, platformSmallTexture, platformSmallTextureIce, platformSmallTextureStone, platformBigTexture, platformBigTextureIce, platformBigTextureStone);

	float deltaTime = 0.0f;
	sf::Clock clock;
	player.canDMG = true;
	while (window.isOpen())  /*!<Pentla gry */
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;


		sf::Event evnt;
		if (okno == 0) {
			while (window.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case sf::Event::KeyReleased:
					switch (evnt.key.code)
					{
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;

					case sf::Keyboard::Down:
						menu.MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (menu.GetPressedItem())
						{
						case 0:
							okno = 1;
							break;
						case 1:
							okno = 10;
							break;
						case 2:
							window.close();
							break;
						}
						break;
					}
					break;


				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					ResizeView(window, view);
					break;
				}
			}
			window.clear();
			menu.draw(window);
		}

		if (okno == 10) {
			while (window.pollEvent(evnt))
			{
				std::cout << "tworze okno" << std::endl;

				switch (evnt.type)
				{
				case sf::Event::KeyReleased:
					switch (evnt.key.code)
					{
					case sf::Keyboard::Up:
						opcje.MoveUp();
						break;

					case sf::Keyboard::Down:
						opcje.MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (opcje.GetPressedItem())
						{
						case 0:
							lvl = 1;
							break;
						case 1:
							lvl = 1.25;
							break;
						case 2:
							lvl = 1.5;
							break;
						case 3:
							okno = 0;
							break;
						}
						break;
					}
					break;


				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					ResizeView(window, view);
					break;

				
				}
			}
			window.clear();
			opcje.draw(window);


		}

		if (okno == 1){

			view.setCenter(player.GetPosition());
			window.clear();
			window.draw(backgroundSprite);
			window.setView(view);

			player.Update(deltaTime);
			for (Enemy& goblinyy : gobliny)
				goblinyy.Update(deltaTime);

			ork1.Update(deltaTime);

			player.body.setScale(sf::Vector2f(0.25f, 0.25f));

			for (Enemy& goblinyy : gobliny)
				goblinyy.body.setScale(sf::Vector2f(0.1f, 0.1f));
		
			ork1.body.setScale(sf::Vector2f(0.2f, 0.2f));

			std::string playerHP = "HP " + std::to_string(player.getHP());
			sf::Text text(playerHP, font, 30);
			text.setFillColor(sf::Color(155, 0, 0));
			text.setPosition(player.GetPosition() - sf::Vector2f(250, 180));

			ground.Draw(window);
			ground1.Draw(window);

			for (Platform& platformy : small)
				platformy.Draw(window);
			for (Platform& platformy : big)
				platformy.Draw(window);
			
			player.Draw(window);

			for (Enemy& goblinyy : gobliny)
				goblinyy.Draw(window);

			ork1.Draw(window);
			

			for (Enemy& goblinyy : gobliny) {
				odleglosc = player.GetPosition().x - goblinyy.GetPosition().x;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (abs(odleglosc) <= 70))
				{
					if (counter < 400) {
						counter++;
					}
					else
					{
						std::cout << "Zadaje dmg" << std::endl;
						goblinyy.dealDMG(player.getATK());

						counter = 0;
					}
				}

			}

			odleglosc = player.GetPosition().x - ork1.GetPosition().x;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (abs(odleglosc) <= 70))
			{
				if (counter < 400) {
					counter++;
				}
				else
				{
					std::cout << "Zadaje dmg" << std::endl;
					ork1.dealDMG(player.getATK());

					counter = 0;
				}
			}

			for (Enemy& goblinyy : gobliny) {
			
				if (collision::PixelPerfectTest(player.getSprite(), goblinyy.getSprite()))
				{
					if (player.canDMG == true)
						player.dealDMG(goblinyy.getATK());


					if (counter < 800) {

						player.canDMG = false;
						counter++;
					}
					else
					{
						counter = 0;
						player.canDMG = true;
					}

				}

			}

			if (collision::PixelPerfectTest(player.getSprite(), ork1.getSprite()))
			{
				if (player.canDMG == true)
					player.dealDMG(ork1.getATK());


				if (counter < 800) {

					player.canDMG = false;
					counter++;
				}
				else
				{
					counter = 0;
					player.canDMG = true;
				}
			}

			if (collision::PixelPerfectTest(player.getSprite(), ground.getSprite()))
			{
				player.canJump = true;
				player.velocity.y = 0.0f;
			}
			if (collision::PixelPerfectTest(player.getSprite(), ground1.getSprite()))
			{

				player.canJump = true;
				player.velocity.y = 0.0f;
			}

			for (Platform& platformy : small)
			if (collision::PixelPerfectTest(player.getSprite(), platformy.getSprite()))
			{
				player.canJump = true;
				player.velocity.y = 0.0f;
			}

			for (Platform& platformy : big)
				if (collision::PixelPerfectTest(player.getSprite(), platformy.getSprite()))
				{
					player.canJump = true;
					player.velocity.y = 0.0f;
				}
			window.draw(text);

			if (player.getHP() <= 0)
				lose(window, font,view);

			if (Enemy::licznikPrzeciwnikow == 6) {
				player.body.setPosition(300.0f, 1443.0f);
				for (Platform& plat:small)
				{
					small.pop_back();
				}

				for (Platform& plat : big)
				{
					big.pop_back();
				}

				for (Enemy& goblinyy : gobliny)
				{
					gobliny.pop_back();
				}
				player.setHP(300);
				player.setATK(15);
				okno = 2;
			}
		}

		if (okno == 2)
		{			
			view.setCenter(player.GetPosition());
			window.clear();
			window.draw(backgroundSprite);
			window.setView(view);

			backgroundSprite.setPosition(0, 0);
			backgroundSprite.setTexture(backgroundTextureIce);

			player.Update(deltaTime);

			for (Enemy& golemy : golemE)
				golemy.Update(deltaTime);

			ice1.Update(deltaTime);

			player.body.setScale(sf::Vector2f(0.25f, 0.25f));

			for (Enemy& golemy : golemE)
				golemy.body.setScale(sf::Vector2f(0.15f, 0.15f));

			ice1.body.setScale(0.2, 0.2);

			std::string playerHP = "HP " + std::to_string(player.getHP());
			sf::Text text(playerHP, font, 30);
			text.setFillColor(sf::Color(155, 0, 0));
			text.setPosition(player.GetPosition() - sf::Vector2f(250, 180));

			window.draw(text);
			groundIce.Draw(window);
			groundIce1.Draw(window);

			for (Platform& platformy : smallIce)
				platformy.Draw(window);
			for (Platform& platformy : bigIce)
				platformy.Draw(window);

			player.Draw(window);

			ice1.Draw(window);

			for (Enemy& golemy : golemE)
				golemy.Draw(window);


			for (Enemy& golemy : golemE) {
				odleglosc = player.GetPosition().x - golemy.GetPosition().x;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (abs(odleglosc) <= 70))
				{
					if (counter < 400) {
						counter++;
					}
					else
					{
						std::cout << "Zadaje dmg" << std::endl;
						golemy.dealDMG(player.getATK());

						counter = 0;
					}
				}

			}

			odleglosc = player.GetPosition().x - ice1.GetPosition().x;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (abs(odleglosc) <= 70))
			{
				if (counter < 400) {
					counter++;
				}
				else
				{
					std::cout << "Zadaje dmg" << std::endl;
					ice1.dealDMG(player.getATK());

					counter = 0;
				}
			}

			for (Enemy& golemy : golemE) {

				if (collision::PixelPerfectTest(player.getSprite(), golemy.getSprite()))
				{
					if (player.canDMG == true)
						player.dealDMG(golemy.getATK());

					if (counter < 800) {

						player.canDMG = false;
						counter++;
					}
					else
					{
						counter = 0;
						player.canDMG = true;
					}

				}

			}

			if (collision::PixelPerfectTest(player.getSprite(), ice1.getSprite()))
			{
				if (player.canDMG == true)
					player.dealDMG(ice1.getATK());


				if (counter < 800) {

					player.canDMG = false;
					counter++;
				}
				else
				{
					counter = 0;
					player.canDMG = true;
				}

			}

			if (collision::PixelPerfectTest(player.getSprite(), groundIce.getSprite()))
			{
				player.canJump = true;
				player.velocity.y = 0.0f;
			}

			if (collision::PixelPerfectTest(player.getSprite(), groundIce1.getSprite()))
			{

				player.canJump = true;
				player.velocity.y = 0.0f;
			}

			for (Platform& platformy : smallIce)
				if (collision::PixelPerfectTest(player.getSprite(), platformy.getSprite()))
				{
					player.canJump = true;
					player.velocity.y = 0.0f;
				}

			for (Platform& platformy : bigIce)
				if (collision::PixelPerfectTest(player.getSprite(), platformy.getSprite()))
				{
					player.canJump = true;
					player.velocity.y = 0.0f;
				}

			window.draw(text);

			if (player.getHP() <= 0)
				lose(window, font, view);

			if (Enemy::licznikPrzeciwnikow == 1) {
				player.body.setPosition(300.0f, 1443.0f);
				for (Platform& plat : smallIce)
				{
					smallIce.pop_back();
				}

				for (Platform& plat : bigIce)
				{
					bigIce.pop_back();
				}

				for (Enemy& goblinyy : golemE)
				{
					golemE.pop_back();
				}
				player.setHP(300);
				player.setATK(15);
				okno = 3;
			}
		}

		if (okno == 3)
		{			
			view.setCenter(player.GetPosition());
			window.clear();
			window.draw(backgroundSprite);
			window.setView(view);

			backgroundSprite.setScale(1, 1);
			backgroundSprite.setPosition(0, 700);
			backgroundSprite.setTexture(backgroundTextureStone);

			player.Update(deltaTime);
			player.body.setScale(sf::Vector2f(0.25f, 0.25f));

			boss.Update(deltaTime);
			boss.body.setScale(sf::Vector2f(0.25f, 0.25f));


			std::string playerHP = "HP " + std::to_string(player.getHP());
			sf::Text text(playerHP, font, 30);
			text.setFillColor(sf::Color(155, 0, 0));
			text.setPosition(player.GetPosition() - sf::Vector2f(250, 180));

			window.draw(text);
			groundStone.Draw(window);

			for (Platform& platformy : smallStone)
				platformy.Draw(window);

			for (Platform& platformy : bigStone)
				platformy.Draw(window);

			player.Draw(window);

			boss.Draw(window);

			odleglosc = player.GetPosition().x - boss.GetPosition().x;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (abs(odleglosc) <= 70))
				{
					if (counter < 400) {
						counter++;
					}
					else
					{
						std::cout << "Zadaje dmg" << std::endl;
						boss.dealDMG(player.getATK());
						counter = 0;
					}
				}

				if (collision::PixelPerfectTest(player.getSprite(), boss.getSprite()))
				{
					if (player.canDMG == true)
						player.dealDMG(boss.getATK());


					if (counter < 800) {

						player.canDMG = false;
						counter++;
					}
					else
					{
						counter = 0;
						player.canDMG = true;
					}

				}

			if (collision::PixelPerfectTest(player.getSprite(), groundStone.getSprite()))
			{
				player.canJump = true;
				player.velocity.y = 0.0f;
			}

			for (Platform& platformy : smallStone)
				if (collision::PixelPerfectTest(player.getSprite(), platformy.getSprite()))
				{
					player.canJump = true;
					player.velocity.y = 0.0f;
				}

			for (Platform& platformy : bigStone)
				if (collision::PixelPerfectTest(player.getSprite(), platformy.getSprite()))
				{
					player.canJump = true;
					player.velocity.y = 0.0f;
				}

			window.draw(text);

			if (player.getHP() <= 0)
				lose(window, font, view);

			if (Enemy::licznikPrzeciwnikow == 0) {

				win(window,font,view);

				for (Platform& plat : smallStone)
				{
					smallStone.pop_back();
				}

				for (Platform& plat : bigStone)
				{
					bigStone.pop_back();
				}

				player.setHP(300);
				player.setATK(15);
				okno = 3;
			}

		}
		window.display();
	}
	return 0;
}
