#include "first_spot_player.hpp"

FirstSpotPlayer::FirstSpotPlayer(Board* inputted_board, Rules* rules_ptr, string symbol, int usernum)
{
    this->board = inputted_board;
    this->rules = rules_ptr;
    usernumber = usernum;
    board->set_mark(usernum, symbol);
}

void FirstSpotPlayer::move(int user)
{
    for (int i = 1; i <= 9; i++)
    {
        string mark = board->get_mark(i);
        if (mark == " ")
        {
            cout << endl;
            board->make_move(i, board->get_user(usernumber));
            break;
        }
    }
}