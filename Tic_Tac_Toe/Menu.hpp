#pragma once
#include <iostream>
#include "Game.hpp"
#include "ExitMenu.hpp"

class MainMenu
{
    Board* board;
    Rules* rules;
    ConsoleBoardCreator* creator;
    Player* player_one;
    Player* player_two;
    string default_key;
    int usernum;

public:
	MainMenu(Board* aboard, ConsoleBoardCreator* acreator, Rules* arule);
	void Rungame(string defaul = "No");
    void Chooseplayers();
};