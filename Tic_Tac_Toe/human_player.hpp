#pragma once
#include <string>
#include "Player.hpp"
#include "Game.hpp"
#include "board.hpp"

class HumanPlayer : public Player
{
private:
	Board* board;
	Rules* rules;
	string symbol;
	int usernumber;

public:
	HumanPlayer(Board* inputted_board, Rules* rules_ptr, string symbol, int usernum);
	void move(int user) override;
};