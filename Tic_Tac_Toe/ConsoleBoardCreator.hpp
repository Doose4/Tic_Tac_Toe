#pragma once
#include <iostream>
#include <string>
#include <array>
#include "board.hpp"
using namespace std;

class ConsoleBoardCreator
{
    Board* board;
    int board_size;

public:
    ConsoleBoardCreator(Board* inputted_board, int size = 3);
    string formatted_board();
};