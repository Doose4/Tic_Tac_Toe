#include <iostream>
#include <string>
#include "ConsoleBoardCreator.hpp"
using namespace std;

//sets the board
ConsoleBoardCreator::ConsoleBoardCreator(Board* inputted_board, int size)
{
    this->board = inputted_board;
    this->board_size = size;
};

//displays formated board
string ConsoleBoardCreator::formatted_board()
{
    string outputt = "\n";


    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (j == 0) {
                outputt = outputt + "  " + board->get_mark((i * board_size) + j+1);
            }
            else {
                outputt = outputt + " | " + board->get_mark((i * board_size) + j+1);
            }
        }
        if (i != board_size-1)
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