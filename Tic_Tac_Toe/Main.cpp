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

    //set rules rules for program
    Rules rules = Rules(board_ptr);

    //Too low out of tolarance
    assert(rules.validate_input(-20) == false);

    //Too high out of tolarance
    assert(rules.validate_input(20) == false);

    //Within tolarance but already taken
    assert(rules.validate_input(7) == false);

    //Within tolarance AND empty
    assert(rules.validate_input(6) == true);

    //Makes a three in a row 
    board.make_move(1, 'X');
    board.make_move(2, 'X');
    board.make_move(3, 'X');

    bool in_progress = rules.in_progress();

    assert(in_progress == false);

    return 0;
}