#include <iostream>
#include "rules.hpp"
#include "Player.hpp"
#include "first_spot_player.hpp"
#include "second_spot_player.hpp"
#include "human_player.hpp"
using namespace std;

class Game
{
private:
    Board* board;
    Rules* rules;
    ConsoleBoardCreator* creator;
    Player* player_one;
    Player* player_two;
    Player* current_player;
    int usernum;
    void switch_player();

public:
    Game(Board* board_ptr, Rules* rules_ptr, ConsoleBoardCreator* creator_ptr, Player* player_one_ptr, Player* player_two_ptr);
    int validate_user_input(int value_input);
    void reset();
    void start();
    void print_end_game_message(char return_character);
};