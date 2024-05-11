#include <iostream>
#include <string>
#include <array>
#include "board.hpp"
using namespace std;

//Creates Board
Board::Board(int bsize)
{
    board_size = bsize;
    this->create_empty_board();
};

//Resets thte board so it's empty
void Board::create_empty_board()
{
    board.clear();
    int endline = board_size * board_size;
    for (int i = 0; i < (endline); i++)
    {
        board.push_back("_");
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

int Board::get_board_size() {
    return board_size;
};

string Board::help_board()
{
    string outputt = "\n";


    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (j == 0) {
                outputt = outputt + "  " + to_string((i * board_size) + j + 1);
            }
            else {
                outputt = outputt + " | " + to_string((i * board_size) + j + 1);
            }
        }
        if (i != board_size - 1)
        {
            outputt = outputt + "\n" + " -";
            for (int j = 0; j < board_size - 1; j++) {
                outputt = outputt + "-----";
            }
            outputt = outputt + "\n";
        }

    }
    return outputt;

};