#include <iostream>
#include "rules.hpp"
using namespace std;

class Game
{
private:
    Board* board;
    Rules* rules;
    ConsoleBoardCreator* creator;

public:
    Game(Board* board_ptr, Rules* rules_ptr, ConsoleBoardCreator* creator_ptr);
    string get_user_char(int user);
    int validate_user_input(int value_input);
    void start();
    void print_end_game_message(char return_character);
};