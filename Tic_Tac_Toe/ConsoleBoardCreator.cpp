#include <iostream>
#include <string>
#include "ConsoleBoardCreator.hpp"
using namespace std;

//sets the board
ConsoleBoardCreator::ConsoleBoardCreator(Board* inputted_board)
{
    board = inputted_board;
};

//displays formated board
string ConsoleBoardCreator::formatted_board()
{
    return create_row(0) + create_row(1) + create_row(2) + "\n";
};

//creates each line in the board
string ConsoleBoardCreator::create_row(int mult) {
    int man = mult * 3;
    if (mult<2){
        return " " + board->get_mark(man + 1) + " | " + board->get_mark(man + 2) +
            " | " + board->get_mark(man + 3) + " \n-----------\n";
    }
    return " " + board->get_mark(man+1) + " | " + board->get_mark(man+2) + 
        " | " + board->get_mark(man+3);
};