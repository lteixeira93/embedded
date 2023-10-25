#include <iostream>
#include "Player.hpp"

Player::Player(const Player &source) 
: name {source.name}, xp {source.xp}
{
    std::cout << "Copy created from " << source.name << std::endl;
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

