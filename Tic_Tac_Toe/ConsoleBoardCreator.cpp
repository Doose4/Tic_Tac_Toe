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
    return create_row(0) + create_row(1) + create_row(2) + "\n";
};

string ConsoleBoardCreator::create_row(int mult) {
    int man = mult * 3;
    if (mult<2){
        return " " + board->get_mark(man + 1) + " | " + board->get_mark(man + 2) +
            " | " + board->get_mark(man + 3) + " \n-----------\n";
    }
    return " " + board->get_mark(man+1) + " | " + board->get_mark(man+2) + 
        " | " + board->get_mark(man+3);
};