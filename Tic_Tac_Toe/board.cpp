#include <iostream>
#include <string>
#include <array>
#include "board.hpp"
using namespace std;

//Creates Board
Board::Board()
{
    this->create_empty_board();
    for (int i = 0; i < 2; i++)
    {
        usedmarks[i] = "_";
    }
};

//Resets thte board so it's empty
void Board::create_empty_board()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = "_";
    }
}

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

void Board::set_mark(int usernum, string usermark) {
    usedmarks[usernum-1] = usermark;
};

string Board::get_user(int usernum) {
    return usedmarks[usernum-1];

};