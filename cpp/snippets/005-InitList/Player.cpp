#include <iostream>
#include "Player.hpp"

Player::Player() 
: Player {"None", 0} // Delegates to 2 args constructor
{
    std::cout << "[NO-ARGS] Object Player created" << std::endl;
}

Player::Player(std::string name_val) 
: Player {name_val, 0}
{
    std::cout << "[NAME-ARG] Object Player created" << std::endl;
}

Player::Player(std::string name_val, int xp_val) // Has default values define in the prototype
: name {name_val}, xp {xp_val}
{
    std::cout << "[NAME-AND-XP-ARGS] Object Player created" << std::endl;
}

Player::~Player()
{
    std::cout << "Object Player destroyed" << std::endl;
}

