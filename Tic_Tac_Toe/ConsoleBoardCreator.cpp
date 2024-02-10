#include <iostream>
#include <string>
#include "ConsoleBoardCreator.hpp"
using namespace std;

ConsoleBoardCreator::ConsoleBoardCreator(Board* inputted_board)
{
    board = inputted_board;
};

string ConsoleBoardCreator::formatted_board()
{
    // This implementation is incomplete. Make sure you fill in the rest! It would also help to break this long string up using some private methods.
    return " " + board->get_mark(1) + " | " + board->get_mark(2) + " | " + board->get_mark(3) + " \n-----------\n   |   |   \n-----------\n   |   |   ";
};