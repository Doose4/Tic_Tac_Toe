#include <iostream>
#include "human_player.hpp"

HumanPlayer::HumanPlayer(Board* inputted_board, Rules* rules_ptr, string element, int usernum)
{
    this->board = inputted_board;
    this->rules = rules_ptr;
    usernumber = usernum;
    board->set_mark(usernum, element);
}

void HumanPlayer::move(int user)
{
    //cout << endl << symbol;
    int input = 0;
    while (input == 0)
    {
        std::cout << "Player " << user << ", What cell, 1-9, do you want to mark? ";
        cin >> input;
        cin.clear();
        cin.ignore(256, '\n');
        if (rules->validate_input(input))
        {
            //string symbol = symbol;
            board->make_move(input, board->get_user(usernumber));
            
        }
        else {
            input = 0;
        }
    }
}