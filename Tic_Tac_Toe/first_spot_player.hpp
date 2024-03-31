#pragma once
#include "rules.hpp"
#include "player.hpp"

class FirstSpotPlayer : public Player
{
private:
	Board* board;
	Rules* rules;
	string symbol;

public:
	FirstSpotPlayer(Board* inputted_board, Rules* rules_ptr, string symbol);
	void move(int user) override;
};