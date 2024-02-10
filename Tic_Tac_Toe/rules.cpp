#include <iostream>
#include <string>
#include "rules.hpp"
using namespace std;


Rules::Rules(Board* inputted_board)
{
    board = inputted_board;
};

bool Rules::validate_input(int input)
{
    if (input < 1 || input > 9 || board->get_mark(input)!=" ")
    {
        return false;
    }

    return true;
};

char Rules::in_progress()
{    
    if (three_in_a_row() == "X")
    {
        return 'X';
    } else if (three_in_a_row() == "O") {
        return 'O';
    } else if (cats_game()== true) {
        return 'C';
    }
    return '_';
};

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

bool Rules::cats_game() {
    for (int i = 1; i < 10; i++) {
        if (board->get_mark(i) == " ") return false;
    }
    return true;
};