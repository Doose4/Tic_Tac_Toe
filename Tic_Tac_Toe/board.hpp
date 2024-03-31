#include <string>
#pragma once
#include <array>
using namespace std;

class Board
{
    array<string, 9> board;
    array<string, 2> usedmarks;

public:
    explicit Board();
    void create_empty_board();
    void make_move(int cell, string mark);
    string get_mark(int cell);
    void set_mark(int usernum, string usermark);
    string get_user(int usernum);
};