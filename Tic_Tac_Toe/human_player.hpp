#include "Player.hpp"
#include "rules.hpp"

class Human_Player : public Player
{
private:
	Board* board;
	char player_char;

public:
	Human_Player(Board* inputted_board);
	void move() override;
	char get_character() override;
};