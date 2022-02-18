#pragma once
#include "pch.h"
#include "card.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Deck
{
public:
	std::vector<Card> talia;
	Deck()
	{
		talia.push_back(Card(1, "AH.png"));
		talia.push_back(Card(1, "AD.png"));
		talia.push_back(Card(1, "AC.png"));
		talia.push_back(Card(1, "AS.png"));

		talia.push_back(Card(2, "2H.png"));
		talia.push_back(Card(2, "2D.png"));
		talia.push_back(Card(2, "2C.png"));
		talia.push_back(Card(2, "2S.png"));

		talia.push_back(Card(3, "3H.png"));
		talia.push_back(Card(3, "3D.png"));
		talia.push_back(Card(3, "3C.png"));
		talia.push_back(Card(3, "3S.png"));

		talia.push_back(Card(4, "4H.png"));
		talia.push_back(Card(4, "4D.png"));
		talia.push_back(Card(4, "4C.png"));
		talia.push_back(Card(4, "4S.png"));

		talia.push_back(Card(5, "5H.png"));
		talia.push_back(Card(5, "5D.png"));
		talia.push_back(Card(5, "5C.png"));
		talia.push_back(Card(5, "5S.png"));

		talia.push_back(Card(6, "6H.png"));
		talia.push_back(Card(6, "6D.png"));
		talia.push_back(Card(6, "6C.png"));
		talia.push_back(Card(6, "6S.png"));

		talia.push_back(Card(7, "7H.png"));
		talia.push_back(Card(7, "7D.png"));
		talia.push_back(Card(7, "7C.png"));
		talia.push_back(Card(7, "7S.png"));

		talia.push_back(Card(8, "8H.png"));
		talia.push_back(Card(8, "8D.png"));
		talia.push_back(Card(8, "8C.png"));
		talia.push_back(Card(8, "8S.png"));

		talia.push_back(Card(9, "9H.png"));
		talia.push_back(Card(9, "9D.png"));
		talia.push_back(Card(9, "9C.png"));
		talia.push_back(Card(9, "9S.png"));

		talia.push_back(Card(10, "10H.png"));
		talia.push_back(Card(10, "10D.png"));
		talia.push_back(Card(10, "10C.png"));
		talia.push_back(Card(10, "10S.png"));

		talia.push_back(Card(10, "JH.png"));
		talia.push_back(Card(10, "JD.png"));
		talia.push_back(Card(10, "JC.png"));
		talia.push_back(Card(10, "JS.png"));

		talia.push_back(Card(10, "QH.png"));
		talia.push_back(Card(10, "QD.png"));
		talia.push_back(Card(10, "QC.png"));
		talia.push_back(Card(10, "QS.png"));

		talia.push_back(Card(10, "KH.png"));
		talia.push_back(Card(10, "KD.png"));
		talia.push_back(Card(10, "KC.png"));
		talia.push_back(Card(10, "KS.png"));
	}

	Card DrawCard()
	{
		int wylosowana = rand() % talia.size();

		while (talia[wylosowana].inDeck != true)
		{
			wylosowana = rand() % talia.size();
		}
		if (talia[wylosowana].inDeck == true)
		{
			Card DrawnCard = talia[wylosowana];
			talia[wylosowana].inDeck = false;
			return DrawnCard;
		}
	}

	int size()
	{
		return talia.size();
	}

	void carmack()
	{
		talia[talia.size() - 1] = Card(10, "KSC.png");
		talia[talia.size() - 2] = Card(10, "KCC.png");
		talia[talia.size() - 3] = Card(10, "KDC.png");
		talia[talia.size() - 4] = Card(10, "KHC.png");
	}
	void reset()
	{
		for (int i = 0; i < talia.size(); i++)
		{
			talia[i].inDeck = true;
		}
	}
};