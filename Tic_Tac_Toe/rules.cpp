#include <iostream>
#include <string>
#include "rules.hpp"
using namespace std;

//sets board
Rules::Rules(Board* inputted_board, int size)
{
    board = inputted_board;
    this->boardsize = size;
};

//checks if input is taken
bool Rules::validate_input(int input)
{
    int endline = boardsize * boardsize;
    if (input < 1 || input > (endline) || board->get_mark(input) != " ")
    {
        return false;
    }
    return true;
};

//checks whether game is in progress
char Rules::in_progress()
{    
    string winner = three_in_a_row();
    if (winner == board->get_user(1))
    {
        return 'X';
    } else if (winner == board->get_user(2)) {
        return 'O';
    } else if (cats_game()== true) {
        return 'C';
    }
    return '_';
};

//sees if there is a winner
string Rules::three_in_a_row()
{
    for (int i = 0; i < boardsize; i++) {
        if (transitional_test((i*boardsize)+1, "row") != "_") {
            return board->get_mark((i * boardsize) + 1);
        }
    }

    for (int i = 1; i <= boardsize; i++) {
        if (transitional_test(i, "column") != "_") {
            return board->get_mark(i);
        }
    }
    
    if (transitional_test(1, "diag") != "_") {
        return board->get_mark(1);
    }

    if (transitional_test(boardsize,"diag") != "_") {
        return board->get_mark(boardsize);
    }
    return "_";
};

//tests for three in a row taking in three locations
string Rules::transitional_test(int frst, string direction)
{
    int output1 = 0;
    int change;

    if (direction == "row") {
        change = 1;
    }
    else if (direction == "column") {
        change = boardsize;
    }
    else {
        if (frst > 1)
        {
            change = boardsize - 1;
        }
        else {
            change = boardsize + 1;
        }

    }

    //1,4,7
    string markvalue;
    for (int i = 0; i < boardsize-1; i++)
    {
        markvalue = board->get_mark(frst + (i * change));
        if (markvalue != board->get_mark(frst + ((i+1) * change)) || markvalue == " ") {
            output1 = 1;
        }
    }

    if (output1 ==1)
    {
        return "_";
    }
    return board->get_mark(frst);
};

//returns whether or not it is a tied game
bool Rules::cats_game() {
    int endline = boardsize * boardsize;
    for (int i = 0; i < (endline); i++) {
        if (board->get_mark(i+1) == " ") return false;
    }
    return true;
};