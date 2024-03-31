#include <iostream>
#include <string>
#include "Menu.hpp"
using namespace std;

//sets board
MainMenu::MainMenu()
{

};

void MainMenu::Rungame() {
    Board board;
    Board* board_ptr = &board;

    ConsoleBoardCreator creator = ConsoleBoardCreator(board_ptr);
    ConsoleBoardCreator* creator_ptr = &creator;

    Rules rules = Rules(board_ptr);
    Rules* rules_ptr = &rules;

    //FirstSpotPlayer player_one = FirstSpotPlayer(&board, &rules, "X");
    HumanPlayer player_two = HumanPlayer(&board, &rules, "O");
    SecondSpotPlayer player_one = SecondSpotPlayer(&board, &rules, "X");

    ExitMenu Exmenu = ExitMenu(&board, &rules);

    Game game = Game(&board, &rules, &creator, &player_one, &player_two);
    
    bool Gamerunning = true;
    while (Gamerunning)
    {
        game.start();
        Gamerunning = Exmenu.Exitout();
    }
};
