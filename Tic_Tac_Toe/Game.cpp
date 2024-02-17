#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

//Sets pointer locations for different sub classes
Game::Game(Board* board_ptr, Rules* rules_ptr, ConsoleBoardCreator* creator_ptr)
{
    board = board_ptr;
    rules = rules_ptr;
    creator = creator_ptr;
};

//get's the user
string Game::get_user_char(int user){
    return board->get_user(user);
};

//Validates the input that the user makes
int Game::validate_user_input(int value_input) {

    if(value_input < 10 && value_input > 0) {
        if (board->get_mark(value_input) == " ") {
            return value_input;
        }
    }
    
    std::cout << "That was not a valid cell! ";
    return 0;
};

//Prints end of game information
void Game::print_end_game_message(char return_character) {
    std::cout << creator->formatted_board();
    switch (return_character)
    {
    case 'X':
        std::cout << "\t\tX won! Good job Player!!\n";
        break;
    case 'O':
        std::cout << "\t\tO won! Good job Player!!\n";
        break;
    case 'C':
        std::cout << "\t\tNobody won! Good job Players!!\n";
        break;
    default:
        break;
    }
};

//Sets up the game
void Game::start()
{
    int input;
    int user = 0;

    while (rules->in_progress() == '_')
    {
        input = 0;
        std::cout << creator->formatted_board();
        while (input == 0) {
            std::cout << "Player " << user +1 << ", What cell, 1-9, do you want to mark? ";
            cin >> input;
            cin.clear();
            cin.ignore(256, '\n');
            input= validate_user_input(input);
        }
        board->make_move(input, get_user_char(user));
        user = (user + 1) % 2;
    }
    print_end_game_message(rules->in_progress());
};