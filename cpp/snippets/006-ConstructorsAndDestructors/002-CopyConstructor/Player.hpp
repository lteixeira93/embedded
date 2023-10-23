#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
	std::string name;
	int xp;
public:
	// Constructor
	Player(std::string name = "None", int xp = 0);

	// Copy constructor - Shallow
	Player(const Player &source);
	
	// Destructor
	~Player();
};

#endif // _PLAYER_H_
