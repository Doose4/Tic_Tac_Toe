#include <iostream>
#include <string>
#include "rules.hpp"
using namespace std;


Rules::Rules(Board* inputted_board)
{
    board = inputted_board;
};

bool Rules::validate_input(int input)
{
    string current_mark = board->get_mark(input);
    if (input < 1 || input > 9 || current_mark != "_")
    {
        return false;
    }

    return true;
};

bool Rules::in_progress()
{
    // We need to ask the Board object if there are any spaces still open.
    // We also need to check if there a winner - three in a row, vertical, horizontal, or diagonal.
    // The code below is a partial implementation where we check for three in a row in the top row.
    if (three_in_a_row_in_the_top_row() == "_")
    {
        return true;
    }
    return false;
};

string Rules::three_in_a_row_in_the_top_row()
{
    if (board->get_mark(1) == board->get_mark(2) && board->get_mark(2) == board->get_mark(3) && board->get_mark(1) != "_")
    {
        return board->get_mark(1);
    }
    else
    {
        return "_";
    }
};