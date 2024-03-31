#include <iostream>
#include <string>
#include "rules.hpp"
using namespace std;

//sets board
Rules::Rules(Board* inputted_board)
{
    board = inputted_board;
};

//checks if input is taken
bool Rules::validate_input(int input)
{
    if (input < 1 || input > 9 || board->get_mark(input) != " ")
    {
        return false;
    }

    return true;
};

//checks whether game is in progress
char Rules::in_progress()
{    
    string winner = three_in_a_row();
    if (winner == "X")
    {
        return 'X';
    } else if (winner == "O") {
        return 'O';
    } else if (cats_game()== true) {
        return 'C';
    }
    return '_';
};

//sees if there is a winner
string Rules::three_in_a_row()
{
    for (int i = 0; i < 3; i++) {
        if (transitional_test((i*3)+1, (i * 3) + 2, (i * 3) + 3) != "_") {
            return board->get_mark(i + 1);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (transitional_test(i+1, i + 4, i + 7) != "_") {
            return board->get_mark(i + 1);
        }
    }
    
    if (transitional_test(1, 5, 9) != "_") {
        return board->get_mark(1);
    }

    if (transitional_test(3, 5, 7) != "_") {
        return board->get_mark(3);
    }
    return "_";
};

//tests for three in a row taking in three locations
string Rules::transitional_test(int frst, int scnd, int thrd)
{
    if (board->get_mark(frst) == board->get_mark(scnd) && board->get_mark(scnd) == board->get_mark(thrd) && board->get_mark(frst) != " ")
    {
        return board->get_mark(1);
    }
    else
    {
        return "_";
    }
};

//returns whether or not it is a tied game
bool Rules::cats_game() {
    for (int i = 1; i < 10; i++) {
        if (board->get_mark(i) == " ") return false;
    }
    return true;
};