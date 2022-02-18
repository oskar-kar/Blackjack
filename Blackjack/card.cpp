#pragma once
#include "pch.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Card
{
public:
	int value; //As = 1 lub 11, Walet, Dama, Król = 10
	bool inDeck;
	sf::Texture tekstura;

	Card()
	{

	}

	Card(int wartosc, std::string plik)
	{
		value = wartosc;
		inDeck = true;
		tekstura.loadFromFile(plik);
	}

	~Card()
	{

	}
};