#include <string>
#pragma once
#include <array>
#include <vector>
using namespace std;

class Board
{
    int board_size;
    vector<string> board;
    array<string, 2> usedmarks;

public:
    explicit Board(int bsize = 3);
    void create_empty_board();
    void make_move(int cell, string mark);
    string get_mark(int cell);
    void set_mark(int usernum, string usermark);
    string get_user(int usernum);
    int get_board_size();
    string help_board();
};