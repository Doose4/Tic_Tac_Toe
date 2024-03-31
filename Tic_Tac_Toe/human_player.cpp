#include <iostream>
#include "human_player.hpp"

HumanPlayer::HumanPlayer(Board* inputted_board, Rules* rules_ptr, string element)
{
    this->board = inputted_board;
    this->rules = rules_ptr;
    this->symbol = element;
}

void HumanPlayer::move(int user)
{
    int input = 0;
    while (input == 0)
    {
        std::cout << "Player " << user << ", What cell, 1-9, do you want to mark? ";
        cin >> input;
        cin.clear();
        cin.ignore(256, '\n');
        if (rules->validate_input(input))
        {
            board->make_move(input, symbol);
        }
        else {
            input = 0;
        }
    }
}