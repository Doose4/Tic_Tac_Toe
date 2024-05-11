#pragma once
#include "rules.hpp"
#include "player.hpp"

class FirstSpotPlayer : public Player
{
private:
	Board* board;
	Rules* rules;
	string symbol;
	int usernumber;
	int boardsize;

public:
	FirstSpotPlayer(Board* inputted_board, Rules* rules_ptr, string symbol, int usernum);
	void move(int user) override;
};