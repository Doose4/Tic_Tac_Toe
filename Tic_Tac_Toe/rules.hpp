#pragma once
#include <iostream>
#include "ConsoleBoardCreator.hpp"
using namespace std;


class Rules
{
    Board* board;
    int boardsize;

public:
    Rules(Board* inputted_board, int size = 3);
    bool validate_input(int input);
    char in_progress();
    string three_in_a_row();
    string transitional_test(int frst, string thrd);
    bool cats_game();
};