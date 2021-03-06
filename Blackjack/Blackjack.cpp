#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "card.cpp"
#include "deck.cpp"
#include "hand.cpp"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>


int main()
{

	float casino_balance = 0.0;
	bool wyplata = true;

	std::ifstream input;
	input.open("casino_balance.txt");
	input >> casino_balance;
	input.close();

	std::srand(std::time(NULL));

	sf::Music music;
	music.openFromFile("Jazz_music.ogg");
	music.setVolume(20.0);
	music.setLoop(true);
	music.play();

	bool boolStart = true;
	bool stawkaWpisanaSound = true;
	sf::SoundBuffer start;
	start.loadFromFile("cardTakeOut.wav");
	sf::Sound startSound;
	startSound.setBuffer(start);
	startSound.setVolume(20.0);

	sf::SoundBuffer card;
	card.loadFromFile("cardSlide.wav");
	sf::Sound cardSlide;
	cardSlide.setBuffer(card);
	cardSlide.setVolume(20.0);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Blackjack made by OK", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	sf::RectangleShape table(sf::Vector2f(1280, 720));
	table.setFillColor(sf::Color::Color(2, 109, 11));

	std::vector<sf::RectangleShape> krupierSlots;
	float krupierSlotsX = 0.0;
	float krupierSlotsY = 0.0;

	sf::Texture emptyTexture;
	emptyTexture.loadFromFile("empty.png");

	for (int i = 0; i < 12; i++)
	{
		sf::RectangleShape slot(sf::Vector2f(138.2, 211.2));
		slot.setPosition(krupierSlotsX, krupierSlotsY);
		slot.setTexture(&emptyTexture);
		krupierSlots.push_back(slot);
		krupierSlotsX += 50;
	}

	std::vector<sf::RectangleShape> playerSlots;
	float playerSlotsX = 0.0;
	float playerSlotsY = 508.8;

	for (int i = 0; i < 12; i++)
	{
		sf::RectangleShape slot(sf::Vector2f(138.2, 211.2));
		slot.setPosition(playerSlotsX, playerSlotsY);
		slot.setTexture(&emptyTexture);
		playerSlots.push_back(slot);
		playerSlotsX += 50;
	}

	Deck talia;
	Hand krupierHand;
	Hand playerHand;

	playerHand.add(talia.DrawCard());
	playerHand.add(talia.DrawCard());

	krupierHand.add(talia.DrawCard());
	krupierHand.add(talia.DrawCard());

	sf::Texture cover;
	cover.loadFromFile("red_back.png");
	int kolor = 0;

	bool stawkaWpisana = false;
	std::string stawkaString = "";
	long long int stawka = 0;

	bool pierwszaKrupiera = true;
	bool zakryta = true;

	bool turaGracza = true;

	bool wygranaKrupiera = false;
	bool wygranaGracza = false;
	bool blackjack = false;
	bool remis = false;
	bool koniecGry = false;

	sf::Text koniec;
	sf::Font Arialbi;
	Arialbi.loadFromFile("arialbi.ttf");
	koniec.setFont(Arialbi);
	koniec.setString("");
	koniec.setCharacterSize(80);
	koniec.setFillColor(sf::Color::White);

	sf::Text wpiszStawke;
	wpiszStawke.setFont(Arialbi);
	wpiszStawke.setString("");
	wpiszStawke.setCharacterSize(24);
	wpiszStawke.setFillColor(sf::Color::White);

	sf::Text stawkaText;
	stawkaText.setFont(Arialbi);
	stawkaText.setString("Bet: ");
	stawkaText.setCharacterSize(48);
	stawkaText.setFillColor(sf::Color::White);
	sf::FloatRect stawkaTextRect = stawkaText.getLocalBounds();
	stawkaText.setOrigin(stawkaTextRect.left, stawkaTextRect.top + stawkaTextRect.height / 2.0);
	stawkaText.setPosition(sf::Vector2f(2.0, 720 / 2.0));

	bool carmackActive = false;
	bool carmackDone = false;

	bool easterActive = false;
	sf::Text easterText;
	easterText.setFont(Arialbi);
	easterText.setString(" ");
	easterText.setCharacterSize(48);
	easterText.setFillColor(sf::Color::White);
	sf::FloatRect easterTextRect = easterText.getLocalBounds();
	easterText.setOrigin(easterTextRect.left, easterTextRect.top + easterTextRect.height / 2.0);
	easterText.setPosition(sf::Vector2f(0.0, 720 / 2.0 + 70.0));

	sf::Text rekaKrupiera;
	rekaKrupiera.setFont(Arialbi);
	rekaKrupiera.setString("");
	rekaKrupiera.setCharacterSize(48);
	rekaKrupiera.setFillColor(sf::Color::White);
	rekaKrupiera.setPosition(600.0, 12.0);

	sf::Text rekaGracza;
	rekaGracza.setFont(Arialbi);
	rekaGracza.setString("");
	rekaGracza.setCharacterSize(48);
	rekaGracza.setFillColor(sf::Color::White);
	rekaGracza.setPosition(600.0, 655.0);

	while (window.isOpen())
	{
		if (boolStart == true)
		{
			startSound.play();
			boolStart = false;
		}

		std::stringstream trescKrupiera;
		std::stringstream trescGracza;

		if (stawkaWpisana == false)
		{	
			wpiszStawke.setString("Place Your bet (Integer only), then press Enter to confirm");
			sf::FloatRect wpiszStawkeRect = wpiszStawke.getLocalBounds();
			wpiszStawke.setOrigin(wpiszStawkeRect.left + wpiszStawkeRect.width / 2.0, wpiszStawkeRect.top + wpiszStawkeRect.height / 2.0);
			wpiszStawke.setPosition(sf::Vector2f(1280 / 2.0, 720 / 2.0));
			playerSlots[0].setTexture(&cover);
			playerSlots[1].setTexture(&cover);
			krupierSlots[0].setTexture(&cover);
			trescKrupiera << "";
			trescGracza << "";
		}

		if (stawkaWpisana == true)
		{
			if (stawkaWpisanaSound == true)
			{
				startSound.play();
				stawkaWpisanaSound = false;
			}
			wpiszStawke.setString("");
			std::stringstream trescStawka;
			trescStawka << "Bet: " << stawka;
			stawkaText.setString(trescStawka.str());
			playerSlots[0].setTexture(&playerHand[0].tekstura);
			playerSlots[1].setTexture(&playerHand[1].tekstura);
			krupierSlots[0].setTexture(&krupierHand[0].tekstura);
			trescGracza << "Player's Hand     Score: " << playerHand.sum();
			if (zakryta == true)
			{
				trescKrupiera << "Dealer's Hand     Score: " << krupierHand.sum() - krupierHand[1].value;
			}
			else
			{
				trescKrupiera << "Dealer's Hand     Score: " << krupierHand.sum();
			}
		}

		if (easterActive == true)
		{
			std::stringstream trescEaster;
			trescEaster << "Casino: " << casino_balance;
			easterText.setString(trescEaster.str());
		}
		else
		{
			easterText.setString("");
		}

		rekaKrupiera.setString(trescKrupiera.str());
		rekaGracza.setString(trescGracza.str());

		if (zakryta == true)
		{
			krupierSlots[1].setTexture(&cover);
		}
		else
		{
			krupierSlots[1].setTexture(&krupierHand[1].tekstura);
		}

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode > 47 && evnt.text.unicode < 58 && stawkaWpisana == false)
				{
					stawkaString += static_cast<char>(evnt.text.unicode);
				}
				break;
			case sf::Event::KeyReleased:
				if (evnt.key.code == sf::Keyboard::Enter && stawkaWpisana == false)
				{
					stawkaWpisana = true;
					stawka = atoi(stawkaString.c_str());
				}
				if (evnt.key.code == sf::Keyboard::K)
				{
					switch (kolor)
					{
					case 0:
						kolor++;
						cover.loadFromFile("green_back.png");
						break;
					case 1:
						kolor++;
						cover.loadFromFile("yellow_back.png");
						break;
					case 2:
						kolor++;
						cover.loadFromFile("blue_back.png");
						break;
					case 3:
						kolor++;
						cover.loadFromFile("purple_back.png");
						break;
					case 4:
						kolor++;
						cover.loadFromFile("gray_back.png");
						break;
					case 5:
						kolor = 0;
						cover.loadFromFile("red_back.png");
						break;
					}
				}
				if (evnt.key.code == sf::Keyboard::H && turaGracza == true && stawkaWpisana == true) //kolejna karta dla gracza
				{
					if (playerHand.sum() < 21)
					{
						playerHand.add(talia.DrawCard());
						cardSlide.play();
						for (int i = 2; i < playerHand.size(); i++)
						{
							playerSlots[i].setTexture(&playerHand[i].tekstura);
						}
						if (playerHand.sum() > 21)
						{
							koniecGry = true;
						}
					}
				}
				if (evnt.key.code == sf::Keyboard::S && stawkaWpisana == true) //koniec tury gracza lub kolejny krok krupiera
				{
					if (pierwszaKrupiera == true)
					{
						turaGracza = false;
						zakryta = false;
						pierwszaKrupiera = false;
						cardSlide.play();
						if (krupierHand.sum() > 16)
						{
							koniecGry = true;
						}
					}
					else
					{
						if (krupierHand.sum() <= 16)
						{
							krupierHand.add(talia.DrawCard());
							cardSlide.play();
							for (int i = 2; i < krupierHand.size(); i++)
							{
								krupierSlots[i].setTexture(&krupierHand[i].tekstura);
							}
							if (krupierHand.sum() > 16)
							{
								koniecGry = true;
							}
						}
					}
				}
				if (evnt.key.code == sf::Keyboard::E && stawkaWpisana == true) //Casino Easter Egg
				{
					if (easterActive == false)
					{
						easterActive = true;
					}
					else if (easterActive == true)
					{
						easterActive = false;
					}
				}
				if (evnt.key.code == sf::Keyboard::C && carmackActive == false) //Carmack Easter Egg
				{
					carmackActive = true;
				}
				if (evnt.key.code == sf::Keyboard::Space && koniecGry == true) //restart gry
				{
					talia.reset();
					playerHand.reset();
					krupierHand.reset();

					for (int i = 0; i < 12; i++)
					{
						playerSlots[i].setTexture(&emptyTexture);
						krupierSlots[i].setTexture(&emptyTexture);
					}

					playerHand.add(talia.DrawCard());
					playerHand.add(talia.DrawCard());

					krupierHand.add(talia.DrawCard());
					krupierHand.add(talia.DrawCard());

					zakryta = true;
					pierwszaKrupiera = true;
					turaGracza = true;
					koniecGry = false;
					wygranaKrupiera = false;
					wygranaGracza = false;
					blackjack = false;
					remis = false;
					koniec.setString("");
					stawkaWpisana = false;
					stawkaString = "";
					stawka = 0;
					stawkaText.setString("Bet: ");
					wyplata = true;
					boolStart = true;
					stawkaWpisanaSound = true;
				}
				if (evnt.key.code == sf::Keyboard::Escape) //wylaczenie gry
				{
					window.close();
				}
				break;
			}
		}

		if (carmackDone == false && carmackActive == true)
		{
			carmackDone = true;

			talia.carmack();
			talia.reset();
			playerHand.reset();
			krupierHand.reset();

			for (int i = 0; i < 12; i++)
			{
				playerSlots[i].setTexture(&emptyTexture);
				krupierSlots[i].setTexture(&emptyTexture);
			}

			playerHand.add(talia.DrawCard());
			playerHand.add(talia.DrawCard());

			krupierHand.add(talia.DrawCard());
			krupierHand.add(talia.DrawCard());

			zakryta = true;
			pierwszaKrupiera = true;
			turaGracza = true;
			koniecGry = false;
			wygranaKrupiera = false;
			wygranaGracza = false;
			blackjack = false;
			remis = false;
			koniec.setString("");
			stawkaWpisana = false;
			stawkaString = "";
			stawka = 0;
			stawkaText.setString("Bet: ");
			wyplata = true;
			boolStart = true;
			stawkaWpisanaSound = true;
		}

		if (koniecGry == true)
		{
			if (playerHand.sum() > 21)
			{
				wygranaKrupiera = true;
			}
			else if (krupierHand.sum() > 21)
			{
				wygranaGracza = true;
			}
			else if (playerHand.sum() == krupierHand.sum())
			{
				remis = true;
			}
			else if (playerHand.sum() == 21 && playerHand.size() == 2)
			{
				blackjack = true;
			}
			else if (playerHand.sum() > krupierHand.sum())
			{
				wygranaGracza = true;
			}
			else if (krupierHand.sum() > playerHand.sum())
			{
				wygranaKrupiera = true;
			}
		}
		
		window.clear(sf::Color::Color(2, 109, 11));
		window.draw(table);
		window.draw(rekaKrupiera);
		window.draw(rekaGracza);
		window.draw(wpiszStawke);
		window.draw(stawkaText);
		window.draw(easterText);

		if (wygranaKrupiera == true)
		{
			koniec.setString("DEALER WON!");
			sf::FloatRect koniecRect = koniec.getLocalBounds();
			koniec.setOrigin(koniecRect.left + koniecRect.width / 2.0, koniecRect.top + koniecRect.height / 2.0);
			koniec.setPosition(sf::Vector2f(1280 / 2.0, 720 / 2.0));
			if (wyplata == true)
			{
				casino_balance = casino_balance + (1.0*stawka);
				wyplata = false;
			}
		}

		if (wygranaGracza == true)
		{
			koniec.setString("PLAYER WON!");
			sf::FloatRect koniecRect = koniec.getLocalBounds();
			koniec.setOrigin(koniecRect.left + koniecRect.width / 2.0, koniecRect.top + koniecRect.height / 2.0);
			koniec.setPosition(sf::Vector2f(1280 / 2.0, 720 / 2.0));
			if (wyplata == true)
			{
				casino_balance = casino_balance - (1.0*stawka);
				wyplata = false;
			}
		}

		if (remis == true)
		{
			koniec.setString("DRAW!");
			sf::FloatRect koniecRect = koniec.getLocalBounds();
			koniec.setOrigin(koniecRect.left + koniecRect.width / 2.0, koniecRect.top + koniecRect.height / 2.0);
			koniec.setPosition(sf::Vector2f(1280 / 2.0, 720 / 2.0));
		}

		if (blackjack == true)
		{
			koniec.setString("BLACKJACK!");
			sf::FloatRect koniecRect = koniec.getLocalBounds();
			koniec.setOrigin(koniecRect.left + koniecRect.width / 2.0, koniecRect.top + koniecRect.height / 2.0);
			koniec.setPosition(sf::Vector2f(1280 / 2.0, 720 / 2.0));
			if (wyplata == true)
			{
				casino_balance = casino_balance - (1.5*stawka);
				wyplata = false;
			}
		}

		window.draw(koniec);

		for (int i = 0; i < playerSlots.size(); i++)
		{
			window.draw(playerSlots[i]);
		}

		for (int i = 0; i < krupierSlots.size(); i++)
		{
			window.draw(krupierSlots[i]);
		}

		window.display();
	}

	std::ofstream output;
	output.open("casino_balance.txt");
	output << casino_balance;
	output.close();

	return 0;
}