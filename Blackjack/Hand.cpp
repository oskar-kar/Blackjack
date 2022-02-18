#pragma once
#include "pch.h"
#include "card.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Hand
{
public:
	std::vector<Card> reka;
	Hand()
	{

	}

	void add(Card karta)
	{
		if (reka.size() < 13)
		{
			reka.push_back(karta);
		}
	}

	int size()
	{
		return reka.size();
	}

	Card &operator[](int i)
	{
		return reka[i];
	}

	int sum()
	{
		int suma = 0;
		int asy = 0;
		for (int i = 0; i < reka.size(); i++)
		{
				if (reka[i].value != 1)
				{
					suma += reka[i].value;
				}
				if (reka[i].value == 1)
				{
					asy++;
				}
		}
		while (asy != 0)
		{
			while (asy > 1)
			{
				suma++;
				asy--;
			}
			if (suma + 11 <= 21)
			{
				suma += 11;
				asy--;
			}
			else
			{
				suma++;
				asy--;
			}
		}
		return suma;
	}

	void reset()
	{
		reka.clear();
	}
};