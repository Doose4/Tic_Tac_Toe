#include <iostream>
#include <array>
#include <cassert>
#include "rules.hpp"

using namespace std;

int main()
{
    Board board;

    board.make_move(1, 'X');
    board.make_move(3, 'X');
    board.make_move(5, 'X');
    board.make_move(7, 'O');

    Board* board_ptr = &board;

    ConsoleBoardCreator creator = ConsoleBoardCreator(board_ptr);
    string formatted_board = creator.formatted_board();
    cout << formatted_board << endl;

    cout << endl;

    board.make_move(1, 'W');

    cout << creator.formatted_board() << endl;

    Rules rules = Rules(board_ptr);

    bool too_low = rules.validate_input(-20);

    assert(too_low == false);

    bool too_high = rules.validate_input(20);

    assert(too_high == false);

    bool just_right_and_not_taken = rules.validate_input(6);

    assert(just_right_and_not_taken == true);

    bool already_taken = rules.validate_input(7);

    assert(already_taken == false);

    board.make_move(1, 'X');
    board.make_move(2, 'X');
    board.make_move(3, 'X');

    bool in_progress = rules.in_progress();

    assert(in_progress == false);

    return 0;
}