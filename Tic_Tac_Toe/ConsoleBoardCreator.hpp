#include <iostream>
#include <string>
#include <array>
#include "board.hpp"
using namespace std;

class ConsoleBoardCreator
{
    Board* board;

public:
    ConsoleBoardCreator(Board* inputted_board);
    string formatted_board();
    string create_row(int multi);
};