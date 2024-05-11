#include <iostream>
#include <string>
#include "Menu.hpp"
using namespace std;

//sets board
MainMenu::MainMenu()
{
    string user_input;
    int board_input;
    bool sizetest = true;
    bool playinput = true;


    while (sizetest)
    {
        cout << "What size game do you want to be played? " << endl;

        cin >> board_input;
        cin.ignore(256, '\n');

        if (board_input > 2)
        {
            this->board_size = board_input;
            sizetest = false;
        }
        else {
            cout << "That size was not valid... Please try again." << endl;
        }
    }

    Board aboard = Board(board_size);
    board = &aboard;
    ConsoleBoardCreator acreator = ConsoleBoardCreator(&aboard, board_size);
    creator = &acreator;
    Rules arules = Rules(&aboard, board_size);
    rules = &arules;

    while (playinput)
    {
        cout << "Are you ready to play?" << endl;
        cin >> user_input;
        cin.ignore(256, '\n');
        if (user_input == "help") {
            cout << "Please open the read me file, else you can type default to run a standard game against a computer or you can type play to choose a custom game. See below board for what numbers to input while playing or type help to see this board while playing.";
            cout << endl << board->help_board() << endl;
        }
        else if (user_input == "default") {
            playinput = false;
            Rungame("default");
        }
        else {
            playinput = false;
            Rungame();
        }
    }

};

void MainMenu::Rungame(string defaul) {
   
    if (defaul == "default") {
        HumanPlayer aplayer_one = HumanPlayer(board, rules, "X", 1);
        player_one = &aplayer_one;
        SecondSpotPlayer aplayer_two = SecondSpotPlayer(board, rules,"O",2);
        player_two = &aplayer_two;
    }     else {
        string userinput;
            
        //set first character
        string usercharacter = "X";

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
            HumanPlayer aplayer_one = HumanPlayer(board, rules, usercharacter, 1);
            player_one = &aplayer_one;
        }
        else {
            cout << endl << "Do you want the computer player to be level 1 or 2? ";
            cin >> userinput;
            cin.clear();
            cin.ignore(256, '\n');
            if (stoi(userinput) == 2) {
                SecondSpotPlayer aplayer_one = SecondSpotPlayer(board, rules, usercharacter, 1);
                player_one = &aplayer_one;
            }
            else {
                FirstSpotPlayer aplayer_one = FirstSpotPlayer(board, rules, usercharacter, 1);
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
            HumanPlayer aplayer_two = HumanPlayer(board, rules, usercharacter, 2);
            player_two = &aplayer_two;
        }
        else {
            cout << endl << "Do you want the computer player to be level 1 or 2? ";
            cin >> userinput;
            cin.clear();
            cin.ignore(256, '\n');
            if (stoi(userinput) == 2) {
                SecondSpotPlayer aplayer_two = SecondSpotPlayer(board, rules, usercharacter, 2);
                player_two = &aplayer_two;
            }
            else {
                FirstSpotPlayer aplayer_two = FirstSpotPlayer(board, rules, usercharacter, 2);
                player_two = &aplayer_two;
            }
        }
    }

    ExitMenu Exmenu = ExitMenu(board);

    Game game = Game(board, rules, creator, player_one, player_two);

    bool Gamerunning = true;
    while (Gamerunning)
    {
        game.start();
        Gamerunning = Exmenu.Exitout();

    }
};