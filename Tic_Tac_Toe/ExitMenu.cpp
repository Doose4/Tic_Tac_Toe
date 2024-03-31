#include <iostream>
#include "ExitMenu.hpp"

using namespace std;

ExitMenu::ExitMenu(Board* inputted_board, Rules* rules_ptr)
{
	this->board = inputted_board;
	this->rules = rules_ptr;
};

bool ExitMenu::Exitout() {
	string userinput;
	cout << "Would you like a rematch Y/N?";
	cin >> userinput;
	char firstletter = userinput[0];
	if (toupper(firstletter) == 'Y')
	{
		board->create_empty_board();
		return true;
	}
	return false;
};