#pragma once
#include <string>
#include "Player.hpp"
#include "rules.hpp"

class HumanPlayer : public Player
{
private:
	Board* board;
	Rules* rules;
	string symbol;

public:
	HumanPlayer(Board* inputted_board, Rules* rules_ptr, string symbol);
	void move(int user) override;
};