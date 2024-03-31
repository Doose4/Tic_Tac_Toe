#include <iostream>
#include <string>
#include "Menu.hpp"
using namespace std;

//sets board
MainMenu::MainMenu(Board* aboard, ConsoleBoardCreator* acreate, Rules* arule)
{
    board = aboard;
    
    creator = acreate;

    rules = arule;
};

void MainMenu::Rungame(string defaul) {
    if (defaul == "default") {
        HumanPlayer aplayer_one = HumanPlayer(board, rules, "X");
        player_one = &aplayer_one;
        SecondSpotPlayer aplayer_two = SecondSpotPlayer(board, rules,"O");
        player_two = &aplayer_two;
    }
    else {
        Chooseplayers();
    }

    ExitMenu Exmenu = ExitMenu(board);

    Game game = Game(board, rules, creator, player_one, player_two);

    bool Gamerunning = true;
    Gamerunning = Exmenu.Exitout();
    while (Gamerunning)
    {
        game.start();
        Gamerunning = Exmenu.Exitout();

    }
};

void MainMenu::Chooseplayers() {
    string userinput;

    //set first character
    string usercharacter="X";

    cout << endl << "Do you want the first player to have a special character? ";
    cin >> userinput;
    cin.clear();
    cin.ignore(256, '\n');

    if (toupper(userinput[0]) == 'Y') {
        cout << endl << "What is the special special character? ";
        cin >> userinput;
        cin.clear();
        cin.ignore(256, '\n');
        usercharacter = userinput[0];
    }

    cout << endl << "Do you want the first player to be a human or computer? ";
    cin >> userinput;
    cin.clear();
    cin.ignore(256, '\n');

    if (toupper(userinput[0]) == 'H') {
        HumanPlayer aplayer_one = HumanPlayer(board, rules, usercharacter);
        player_one = &aplayer_one;
    }
    else {
        cout << endl << "Do you want the computer player to be level 1 or 2? ";
        cin >> userinput;
        cin.clear();
        cin.ignore(256, '\n');
        if (stoi(userinput) == 2){
            SecondSpotPlayer aplayer_one = SecondSpotPlayer(board, rules, usercharacter);
            player_one = &aplayer_one;
        } else {
            FirstSpotPlayer aplayer_one = FirstSpotPlayer(board, rules, usercharacter);
            player_one = &aplayer_one;
        }
    }
    
    //second character selection
    usercharacter = "O";

    cout << endl << "Do you want the second player to have a special character? ";
    cin >> userinput;
    cin.clear();
    cin.ignore(256, '\n');

    if (toupper(userinput[0]) == 'Y') {
        cout << endl << "What is the special special character? ";
        cin >> userinput;
        cin.clear();
        cin.ignore(256, '\n');
        usercharacter = userinput[0];
    }

    cout << endl << "Do you want the second player to be a human or computer? ";
    cin >> userinput;
    cin.clear();
    cin.ignore(256, '\n');

    if (toupper(userinput[0]) == 'H') {
        HumanPlayer aplayer_two = HumanPlayer(board, rules, "O");
        player_one = &aplayer_two;
    }
    else {
        cout << endl << "Do you want the computer player to be level 1 or 2? ";
        cin >> userinput;
        cin.clear();
        cin.ignore(256, '\n');
        if (stoi(userinput) == 2) {
            SecondSpotPlayer aplayer_two = SecondSpotPlayer(board, rules, usercharacter);
            player_one = &aplayer_two;
        }
        else {
            FirstSpotPlayer aplayer_two = FirstSpotPlayer(board, rules, usercharacter);
            player_one = &aplayer_two;
        }
    }

};