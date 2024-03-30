class Player
{
private:
	char player_char;
public:
	virtual void move() = 0;
	virtual char get_character() = 0;
};