#include <iostream>
#include <string>
#include <array>
#include "board.hpp"
using namespace std;

Board::Board()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = "_";
    }
};

void Board::make_move(int cell, string mark)
{
    board[cell - 1] = mark;
};

string Board::get_mark(int cell)
{   
    string symb = board[cell - 1];
    if (symb == "_")
    {
        return " ";
    }
    return symb;
};