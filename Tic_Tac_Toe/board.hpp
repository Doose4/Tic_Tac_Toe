#include <string>
#include <array>
using namespace std;

class Board
{
    array<string, 9> board;
    array<string, 2> marks;

public:
    explicit Board();
    string get_user(int user);
    void set_mark(string user);
    void make_move(int cell, string mark);
    string get_mark(int cell);
};