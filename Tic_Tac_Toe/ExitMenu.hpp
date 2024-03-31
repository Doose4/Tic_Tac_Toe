#include "rules.hpp"

class ExitMenu
{
	Board* board;
	Rules* rules;

public:
	ExitMenu(Board* inputted_board, Rules* rules_ptr);
	bool Exitout();
};