#include "stdafx.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "RPS.h"
#include <string>

int main()
{

	using namespace std;

	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();

	string choice = " ";
	string e_choice = " ";
	string score_s1 = "LVL: ";
	string score_s2 = "1";
	string ARIAL_FONT = "Fonts/arial.ttf";

	int rand;
	int time_lvl = 0;
	float resolution_x = 800;
	float resolution_y = 600;
	int score = 1;

	float title_length = resolution_x / 2.1f;
	float title_width = resolution_y / 12;
	float title_t_length = resolution_x / 2.23f;
	float title_t_width = resolution_y / 12;
	float title_x = resolution_x / 2;
	float title_y = resolution_y / 6;
	float m_butt_length = resolution_x / 5;
	float m_butt_width = resolution_y / 8;
	float m_butt_play_x = resolution_x / 2;
	float m_butt_play_y = resolution_y / 2.5f;
	float m_butt_info_x = resolution_x / 2;
	float m_butt_info_y = resolution_y / 1.75f;
	float m_butt_quit_x = resolution_x / 2;
	float m_butt_quit_y = resolution_y / 1.35f;
	float a_lvl = 1;

	short g = 1;

	bool leave = false;

	sf::RenderWindow pkn_window(sf::VideoMode(resolution_x, resolution_y, 32), "Rock, Paper, Scissor");

	sf::Vector2i Mouse = sf::Mouse::getPosition(pkn_window);

	sf::Font f_arial;
	if (L_FONT(f_arial, ARIAL_FONT))
		return 0;

	sf::Event event;

	sf::Text title_t;
	sf::Text paper_t;
	sf::Text rock_t;
	sf::Text scissor_t;
	sf::Text choice_t;
	sf::Text e_choice_t;
	sf::Text e_choice_t2;
	sf::Text req;
	sf::Text score_t;
	sf::Text m_butt_play_t;
	sf::Text m_butt_info_t;
	sf::Text m_butt_quit_t;

	title_t.setOrigin(title_t_length / 2, title_t_width / 2);
	T_BUTT(title_t, "ROCK, PAPER, SCISSOR?", title_x * resolution_x / 800, title_y);
	title_t.setFont(f_arial);
	title_t.setFillColor(sf::Color::Magenta);
	title_t.setScale(resolution_x / 800, resolution_y / 600);


	T_BUTT(m_butt_play_t, "PLAY", m_butt_play_x - 35, m_butt_play_y - 20);
	m_butt_play_t.setFont(f_arial);
	m_butt_play_t.setFillColor(sf::Color::White);

	T_BUTT(m_butt_info_t, "INFO", m_butt_info_x - 35, m_butt_info_y - 20);
	m_butt_info_t.setFont(f_arial);
	m_butt_info_t.setFillColor(sf::Color::White);

	T_BUTT(m_butt_quit_t, "QUIT", m_butt_quit_x - 35, m_butt_quit_y - 20);
	m_butt_quit_t.setFont(f_arial);
	m_butt_quit_t.setFillColor(sf::Color::White);

	T_BUTT(paper_t, "PAPER", 150, 380);
	paper_t.setFont(f_arial);

	T_BUTT(rock_t, "ROCK", 360, 380);
	rock_t.setFont(f_arial);

	T_BUTT(scissor_t, "SCISSORS", 541, 380); //do poprawy.
	scissor_t.setFont(f_arial);
	scissor_t.setCharacterSize(26);
	scissor_t.setScale(0.9f, 1);

	T_BUTT(choice_t, " ", 260, 480);
	choice_t.setFont(f_arial);
	choice_t.setString("Your Choice: " + choice);

	T_BUTT(e_choice_t, "Your enemy's choice: ", 260, 50);
	e_choice_t.setFont(f_arial);

	T_BUTT(e_choice_t2, " ", 355, 100);
	e_choice_t2.setFont(f_arial);

	T_BUTT(req, "WIN", 355, 153);
	req.setFont(f_arial);

	T_BUTT(score_t, score_s1 + score_s2, 700, 0);
	score_t.setFont(f_arial);
	score_t.setCharacterSize(30);

	sf::RectangleShape title_s;
	sf::RectangleShape m_butt_play_s;
	sf::RectangleShape m_butt_info_s;
	sf::RectangleShape m_butt_quit_s;
	sf::RectangleShape paper;
	sf::RectangleShape rock;
	sf::RectangleShape scissor;
	sf::RectangleShape choice_s;
	sf::RectangleShape e_choice_s;

	D_BUTT(choice_s, 150, 50, 510, 500);
	D_BUTT(e_choice_s, 150, 50, 401, 120);
	D_BUTT(paper, 120, 50, 200, 400);
	D_BUTT(rock, 120, 50, 400, 400);
	D_BUTT(scissor, 120, 50, 600, 400);
	D_BUTT(m_butt_play_s, m_butt_length, m_butt_width, m_butt_play_x, m_butt_play_y);
	D_BUTT(m_butt_info_s, m_butt_length, m_butt_width, m_butt_info_x, m_butt_info_y);
	D_BUTT(m_butt_quit_s, m_butt_length, m_butt_width, m_butt_quit_x, m_butt_quit_y);
	D_BUTT(title_s, title_length, title_width, title_x, title_y);

	sf::ConvexShape time_bar;

	time_bar.setPointCount(4);
	time_bar.setPoint(0, sf::Vector2f(150, 300));
	time_bar.setPoint(1, sf::Vector2f(150, 325));
	time_bar.setPoint(2, sf::Vector2f(650, 325));
	time_bar.setPoint(3, sf::Vector2f(650, 300));

	e_choice_s.setFillColor(sf::Color(152, 251, 152));
	choice_s.setFillColor(sf::Color(152, 251, 152));
	paper.setFillColor(sf::Color(245, 245, 220));
	rock.setFillColor(sf::Color(189, 183, 107));
	scissor.setFillColor(sf::Color(192, 192, 192));
	time_bar.setFillColor(sf::Color::Red);
	m_butt_play_s.setFillColor(sf::Color::Blue);
	m_butt_info_s.setFillColor(sf::Color::Blue);
	m_butt_quit_s.setFillColor(sf::Color::Blue);

	while (pkn_window.isOpen())
	{
		while (pkn_window.pollEvent(event))
		{
			pkn_window.clear(sf::Color(152, 251, 152));

			pkn_window.draw(title_s);
			pkn_window.draw(title_t);

			pkn_window.draw(m_butt_play_s);
			pkn_window.draw(m_butt_play_t);

			pkn_window.draw(m_butt_info_s);
			pkn_window.draw(m_butt_info_t);

			pkn_window.draw(m_butt_quit_s);
			pkn_window.draw(m_butt_quit_t);

			pkn_window.display();
			Mouse = sf::Mouse::getPosition(pkn_window);
			cout << Mouse.x << " " << Mouse.y << "\n";
			if (Mouse.x >= resolution_x / 2.5f && Mouse.y >= resolution_y / 3 &&
				Mouse.x <= resolution_x / 1.67f && Mouse.y <= resolution_y / 2.166064f  &&
				event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				while (pkn_window.isOpen())
				{
					if (leave == true || score == 20)
					{
						leave = false;
						score = 1;
						conversion_str_int(score_s2, score);
						score_t.setString(score_s1 + score_s2);
						break;
					}

					rand = E_Choice(e_choice, e_choice_s, e_choice_t2);
					T_REQ(req, rand);
					clock.restart();

					while (score != 21)
					{
						while (pkn_window.pollEvent(event))
						{
							Mouse = sf::Mouse::getPosition(pkn_window);

							if (event.type == sf::Event::Closed)
							{
								pkn_window.close();
								leave = true;
							}

							if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
								leave = true;

							if (Mouse.y >= 375 && Mouse.x >= 140 &&
								Mouse.y <= 425 && Mouse.x <= 260 &&
								event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
							{
								choice = "PAPER";
								choice_s.setFillColor(sf::Color(245, 245, 220));
								choice_s.setScale(0.8f, 1);
								choice_s.setPosition(490, 500);
							}

							if (Mouse.y >= 375 && Mouse.x >= 340 &&
								Mouse.y <= 425 && Mouse.x <= 460 &&
								event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
							{
								choice = "ROCK";
								choice_s.setFillColor(sf::Color(189, 183, 107));
								choice_s.setScale(0.67f, 1);
								choice_s.setPosition(483, 500);
							}

							if (Mouse.y >= 375 && Mouse.x >= 540 &&
								Mouse.y <= 425 && Mouse.x <= 660 &&
								event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
							{
								choice = "SCISSOR";
								choice_s.setFillColor(sf::Color(192, 192, 192));
								choice_s.setScale(0.9f, 1);
								choice_s.setPosition(507, 500);
							}
						}
						if (leave == true)
							break;

						sf::Time time = clock.getElapsedTime();
						switch (time_lvl)
						{
						case 0:

							time_bar.setPoint(2, sf::Vector2f(650 - (250 * time.asSeconds()), 325));
							time_bar.setPoint(3, sf::Vector2f(650 - (250 * time.asSeconds()), 300));

							break;
						case 1:

							time_bar.setPoint(2, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.1f)), 325));
							time_bar.setPoint(3, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.1f)), 300));

							break;

						case 2:

							time_bar.setPoint(2, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.2f)), 325));
							time_bar.setPoint(3, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.2f)), 300));

							break;

						case 3:

							time_bar.setPoint(2, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.3f)), 325));
							time_bar.setPoint(3, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.3f)), 300));

							break;

						case 4:

							time_bar.setPoint(2, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.4f)), 325));
							time_bar.setPoint(3, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.4f)), 300));

							break;

						case 5:

							time_bar.setPoint(2, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.5f)), 325));
							time_bar.setPoint(3, sf::Vector2f(650 - (250 * time.asSeconds()*(2 + 1 - a_lvl * 2.5f)), 300));

							break;
						};

						choice_t.setString("Your Choice: " + choice);

						pkn_window.clear(sf::Color(152, 251, 152));

						pkn_window.draw(paper);
						pkn_window.draw(paper_t);

						pkn_window.draw(rock);
						pkn_window.draw(rock_t);

						pkn_window.draw(scissor);
						pkn_window.draw(scissor_t);

						pkn_window.draw(choice_s);
						pkn_window.draw(choice_t);

						pkn_window.draw(e_choice_s);
						pkn_window.draw(e_choice_t);
						pkn_window.draw(e_choice_t2);

						pkn_window.draw(time_bar);
						pkn_window.draw(score_t);

						pkn_window.draw(req);

						pkn_window.display();

						if (time.asSeconds() >= 2 * a_lvl)
						{

							if (C_Choice(choice, e_choice, rand))
							{
								score++;
								if (score == 3 * g)
								{
									if (time_lvl < 5)
									{
										a_lvl -= 0.1f;
										time_lvl++;
									}
									g++;
								}
							}
							else
							{
								score = 1;
								a_lvl = 1;
								g = 1;
								time_lvl = 0;
							}
							conversion_str_int(score_s2, score);
							score_t.setString(score_s1 + score_s2);
							choice = " ";
							choice_s.setFillColor(sf::Color(152, 251, 152));
							break;
						}
					}
				}
			}
			if (Mouse.x >= resolution_x / 2.5f && Mouse.y >= resolution_y / 1.96f &&
				Mouse.x <= resolution_x / 1.67f && Mouse.y <= resolution_y / 1.58f &&
				event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				cout << "Brak";
			}
			if (Mouse.x >= resolution_x / 2.5 && Mouse.y >= resolution_y / 1.4742f &&
				Mouse.x <= resolution_x / 1.67f && Mouse.y <= resolution_y / 1.244f &&
				event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ||
				event.type == sf::Event::Closed)
				pkn_window.close();
		}
	}
	return 0;
}