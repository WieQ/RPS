#include "stdafx.h"
#include "RPS.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;
bool L_FONT(sf::Font & font, string name)
{
	sf::RenderWindow error(sf::VideoMode(300, 75, 32), "Error");
	sf::Event zdarzenie;
	if (!(font.loadFromFile(name)))
	{
		while (error.isOpen())
		{
			while (error.pollEvent(zdarzenie))
				if (zdarzenie.type == sf::Event::Closed)
				{
					error.close();
					return true;
				}
			error.clear(sf::Color::White);
			error.display();
		}
	}
	return false;
}

void D_BUTT(sf::RectangleShape & Button, float lenght, float width, float x, float y)
{
	sf::RectangleShape Buttontest(sf::Vector2f(lenght, width));
	Button = Buttontest;
	Button.setOrigin(lenght / 2, width / 2);
	Button.setPosition(x, y);
}

void T_BUTT(sf::Text & text, string name, float x, float y)
{
	text.setString(name);
	text.setFillColor(sf::Color::Black);
	text.setPosition(x, y);

}

bool C_Choice(string p_choice, string e_choice, int random)
{
	switch (random)
	{
	case 0://Win
		if (e_choice == "ROCK" && p_choice == "PAPER" ||
			e_choice == "PAPER" && p_choice == "SCISSOR" ||
			e_choice == "SCISSOR" && p_choice == "ROCK")
			return true;
		else
			return false;
	case 1://Lose
		if (e_choice == "ROCK" && p_choice == "SCISSOR" ||
			e_choice == "PAPER" && p_choice == "ROCK" ||
			e_choice == "SCISSOR" && p_choice == "PAPER")
			return true;
		else
			return false;
	case 2://Draw
		if (e_choice == "ROCK" && p_choice == "ROCK" ||
			e_choice == "PAPER" && p_choice == "PAPER" ||
			e_choice == "SCISSOR" && p_choice == "SCISSOR")
			return true;
		else
			return false;
	case 3://chose PAPER
		if (e_choice == "ROCK" && p_choice == "PAPER" ||
			e_choice == "PAPER" && p_choice == "PAPER" ||
			e_choice == "SCISSOR" && p_choice == "PAPER")
			return true;
		else
			return false;
	case 4://chose ROCK
		if (e_choice == "ROCK" && p_choice == "ROCK" ||
			e_choice == "PAPER" && p_choice == "ROCK" ||
			e_choice == "SCISSOR" && p_choice == "ROCK")
			return true;
		else
			return false;
	case 5://chose SCISSOR
		if (e_choice == "ROCK" && p_choice == "SCISSOR" ||
			e_choice == "PAPER" && p_choice == "SCISSOR" ||
			e_choice == "SCISSOR" && p_choice == "SCISSOR")
			return true;
		else
			return false;
	case 6://don't chose PAPER
		if (e_choice == "ROCK" && p_choice == "ROCK" || p_choice == "SCISSOR" ||
			e_choice == "PAPER" && p_choice == "ROCK" || p_choice == "SCISSOR" ||
			e_choice == "SCISSOR" && p_choice == "ROCK" || p_choice == "SCISSOR")
			return true;
		else
			return false;
	case 7://don't chose ROCK
		if (e_choice == "ROCK" && p_choice == "PAPER" || p_choice == "SCISSOR" ||
			e_choice == "PAPER" && p_choice == "PAPER" || p_choice == "SCISSOR" ||
			e_choice == "SCISSOR" && p_choice == "PAPER" || p_choice == "SCISSOR")
			return true;
		else
			return false;
	case 8://don't chose SCISSOR
		if (e_choice == "ROCK" && p_choice == "ROCK" || p_choice == "PAPER" ||
			e_choice == "PAPER" && p_choice == "ROCK" || p_choice == "PAPER" ||
			e_choice == "SCISSOR" && p_choice == "ROCK" || p_choice == "PAPER")
			return true;
		else
			return false;

	};
	return false;
}

int E_Choice(std::string & choice, sf::RectangleShape & choice_s, sf::Text & choice_t)
{
	srand(time(NULL));
	switch ((std::rand() % 3) + 0)
	{
	case 0:
		choice = "PAPER";

		choice_s.setFillColor(sf::Color(245, 245, 220));
		choice_s.setScale(0.8f, 1);

		choice_t.setPosition(352, 100);
		choice_t.setString("PAPER");

		return ((std::rand() % 9) + 0);
	case 1:
		choice = "ROCK";

		choice_s.setFillColor(sf::Color(189, 183, 107));
		choice_s.setScale(0.67f, 1);
		choice_t.setPosition(360, 100);
		choice_t.setString("ROCK");

		return ((std::rand() % 9) + 0);
	case 2:
		choice = "SCISSOR";

		choice_s.setFillColor(sf::Color(192, 192, 192));
		choice_s.setScale(1, 1);
		choice_t.setPosition(335, 100);
		choice_t.setString("SCISSOR");

		return ((std::rand() % 9) + 0);
	};
}

void T_REQ(sf::Text & text, int rand)
{
	switch (rand)
	{
	case 0:
		text.setString("WIN");
		text.setPosition(355, 153);
		break;
	case 1:
		text.setString("LOSE");
		text.setPosition(355, 153);
		break;
	case 2:
		text.setString("DRAW");
		text.setPosition(355, 153);
		break;
	case 3:
		text.setString("Chose PAPER");
		text.setPosition(300, 153);
		break;
	case 4:
		text.setString("Chose ROCK");
		text.setPosition(310, 153);
		break;
	case 5:
		text.setString("Chose SCISSOR");
		text.setPosition(290, 153);
		break;
	case 6:
		text.setString("Don't chose PAPER");
		text.setPosition(280, 153);
		break;
	case 7:
		text.setString("Don't chose ROCK");
		text.setPosition(285, 153);
		break;
	case 8:
		text.setString("Don't chose SCISSOR");
		text.setPosition(250, 153);
		break;
	};

}

void conversion_str_int(std::string & str, int numb)
{
	stringstream conver;
	conver << numb;
	conver >> str;
}
