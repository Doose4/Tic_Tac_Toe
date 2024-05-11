#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

//Sets pointer locations for different sub classes
Game::Game(Board* board_ptr, Rules* rules_ptr, ConsoleBoardCreator* creator_ptr, Player* player_one_ptr, Player* player_two_ptr)
{
    board = board_ptr;
    rules = rules_ptr;
    creator = creator_ptr;
    player_one = player_one_ptr;
    player_two = player_two_ptr;
    usernum = 1;
};

//resets the game
void Game::reset()
{
    board->create_empty_board();
    current_player = player_one;
}

//switches who the current player is
void Game::switch_player()
{
    if (current_player == player_one)
    {
        current_player = player_two;
        usernum = 2;
    }
    else
    {
        current_player = player_one;
        usernum = 1;
    }
}

//Validates the input that the user makes
int Game::validate_user_input(int value_input) {
    if (rules->validate_input(value_input)) {
        return value_input;
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
        std::cout << "\t\tPlayer 1 won! Good job Player!!\n";
        break;
    case 'O':
        std::cout << "\t\tPlayer 2 won! Good job Player!!\n";
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
    current_player = player_one;
    while (rules->in_progress() == '_')
    {
        std::cout << endl << creator->formatted_board() << endl;
        current_player->move(usernum);
        switch_player();
    }
    cout << endl;
    print_end_game_message(rules->in_progress());
};