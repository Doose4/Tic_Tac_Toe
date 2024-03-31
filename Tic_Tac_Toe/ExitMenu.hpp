#pragma once
#include "board.hpp"

class ExitMenu
{
	Board* board;

public:
	ExitMenu(Board* inputted_board);
	bool Exitout();
};