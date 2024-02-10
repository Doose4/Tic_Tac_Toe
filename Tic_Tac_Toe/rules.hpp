#include <iostream>
#include "ConsoleBoardCreator.hpp"
using namespace std;


class Rules
{
    Board* board;

public:
    Rules(Board* inputted_board);
    bool validate_input(int input);
    bool in_progress();
    string three_in_a_row_in_the_top_row();
};