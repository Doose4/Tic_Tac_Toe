#include "rules.hpp"
#include "player.hpp"

class SecondSpotPlayer : public Player
{
private:
	Board* board;
	Rules* rules;
	string symbol;

public:
	SecondSpotPlayer(Board* inputted_board, Rules* rules_ptr, string symbol);
	void move(int user) override;
};