#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
	std::string name;
	int xp;
public:
	/* Overloaded constructors */
	Player();
	Player(std::string name);
	Player(std::string name, int xp);

	~Player();
};

#endif // _PLAYER_H_
