#include <iostream>
#include "Player.hpp"

int main (void) {
	Player *p0 = new Player();
	Player *p1 = new Player("Hero");
	Player *p2 = new Player("Hero", 10);
	
	delete p0;
	delete p1;
	delete p2;

	return 0;
}