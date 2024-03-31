#include <iostream>
#include "ExitMenu.hpp"

using namespace std;

ExitMenu::ExitMenu(Board* inputted_board)
{
	this->board = inputted_board;
};

bool ExitMenu::Exitout() {
	string userinput;
	cout << "Would you like a rematch Y/N? ";
	cin >> userinput;
	char firstletter = userinput[0];
	if (toupper(firstletter) == 'Y')
	{

		board->create_empty_board();
		return true;
	}
	return false;
};