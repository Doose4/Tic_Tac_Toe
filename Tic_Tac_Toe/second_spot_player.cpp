#include "second_spot_player.hpp"

SecondSpotPlayer::SecondSpotPlayer(Board* inputted_board, Rules* rules_ptr, string symbol, int usernum)
{
    this->board = inputted_board;
    this->rules = rules_ptr;
    this->boardsize = board->get_board_size();
    usernumber = usernum;
    board->set_mark(usernum, symbol);
}

void SecondSpotPlayer::move(int user)
{
    int intput = 0;

    while (intput == 0) {
        intput = rand() % ((boardsize*boardsize)+1);

        if (rules->validate_input(intput))
        {
            cout << endl;
            board->make_move(intput, board->get_user(usernumber));
        }
        else {
            intput = 0;
        }
    }
}