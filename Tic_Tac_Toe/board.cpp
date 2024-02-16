#include <iostream>
#include <string>
#include <array>
#include "board.hpp"
using namespace std;

//Creates Board
Board::Board()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = "_";
    }
    marks[0] = "X";
    marks[1] = "O";
};

//get's the users mark
string Board::get_user(int user) {
    return marks[user];
};

//set's the mark
void Board::make_move(int cell, string mark)
{
    board[cell - 1] = mark;
};

//Returns the mark for the cell
string Board::get_mark(int cell)
{   
    string symb = board[cell - 1];
    if (symb == "_")
    {
        return " ";
    }
    return symb;
};