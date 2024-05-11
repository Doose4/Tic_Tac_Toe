#include <iostream>
#include <array>
#include <cassert>
#include "Menu.hpp"

using namespace std;

//tests different parts of the code
void Tester() {
    Board board;

    board.make_move(1, "X");
    board.make_move(3, "X");
    board.make_move(5, "X");
    board.make_move(7, "O");

    Board* board_ptr = &board;

    ConsoleBoardCreator creator = ConsoleBoardCreator(board_ptr);
    string formatted_board = creator.formatted_board();
    cout << formatted_board << endl;

    cout << endl;

    board.make_move(1, "W");

    cout << creator.formatted_board() << endl;

    //set rules rules for program
    Rules rules = Rules(board_ptr);

    //Too low out of tolarance
    cout << "low bounds" << endl;
    cout << rules.validate_input(-20);
    assert(rules.validate_input(-20) == false);

    //Too high out of tolarance
    cout << "high bounds" << endl;
    assert(rules.validate_input(20) == false);

    //Within tolarance but already taken
    cout << "taken bounds" << endl;
    assert(rules.validate_input(7) == false);

    //Within tolarance AND empty
    cout << "good bounds" << endl;
    assert(rules.validate_input(6) == true);

    //Makes a three in a row 
    board.make_move(1, "X");
    board.make_move(2, "X");
    board.make_move(3, "X");

    char in_progress = rules.in_progress();

    cout << "return winner" << endl;
    assert(in_progress == 'X');
    cout << "testing complete! Thank you";
}

//runs the program
int main()
{
    cout << "\t\t Welcome to Tic-Tac-Toe! Type play to begin!\n\n";

    MainMenu startmenu;

}