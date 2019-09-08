#include "stdafx.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <string>
#ifndef RPS_H_
#define RPS_H_
bool L_FONT(sf::Font & font, std::string name);
void D_BUTT(sf::RectangleShape & Button, float lenght, float width, float x, float y);
void T_BUTT(sf::Text & text, std::string name, float x, float y);
bool C_Choice(std::string p_choice, std::string e_choice, int random);
int E_Choice(std::string & choice, sf::RectangleShape & choice_s, sf::Text & choice_t);
void T_REQ(sf::Text & text, int rand);
void conversion_str_int(std::string & str, int numb);
#endif // RPS_H_
