#include <string>
#include <array>
using namespace std;

class Board
{
    array<string, 9> board;

public:
    explicit Board();
    void make_move(int cell, char mark);
    string get_mark(int cell);
};