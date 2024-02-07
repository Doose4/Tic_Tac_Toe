#include <string>
using namespace std;

class Board
{
private:
	array<string, 9> board;

public:
	string get_name();
	explicit Dog(string name);
	void speak();
};