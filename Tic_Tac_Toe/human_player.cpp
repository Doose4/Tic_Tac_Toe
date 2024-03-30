#include "human_player.hpp"

Human_Player::Human_Player(Board* inputted_board)
{
    this->board = inputted_board;
}

void Human_Player::move()
{
    string user_input = "";
    cout << endl
        << "Which cell?"
        << endl;
    cin >> user_input;
    board->make_move(stoi(user_input), "X");
}

char Human_Player::get_character()
{
    return 'X';
}