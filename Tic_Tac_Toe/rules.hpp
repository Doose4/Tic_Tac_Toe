#pragma once
#include <iostream>
#include "ConsoleBoardCreator.hpp"
using namespace std;


class Rules
{
    Board* board;

public:
    Rules(Board* inputted_board);
    bool validate_input(int input);
    char in_progress();
    string three_in_a_row();
    string transitional_test(int frst, int scnd, int thrd);
    bool cats_game();
};