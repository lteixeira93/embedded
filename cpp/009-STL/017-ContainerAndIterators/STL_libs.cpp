/*
    Create a class Player with name, xp, health attributes
    Create and object player p0 and an empty object p1
    Copy p0 to p1
    Find a specific player inside a vector of players using find STL method
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Player
{
    friend std::ostream &operator<<(std::ostream &os, const Player p)
    {
        std::cout << "[ Hero Display Attributes ]" << std::endl;
        os << "Hero Name: " << p.name << std::endl;
        os << "Hero XP: " << p.xp << std::endl;
        os << "Hero Health: " << p.health << std::endl;

        return os;
    }

private:
    std::string name;
    int xp;
    float health;
public:
    /* Ovl op */
    bool operator==(const Player &rhs) const;

    /* Copy ctor */
    Player(const Player &source);
    
    /* Ctor */
    Player(std::string name_v = "Not Initialized", int xp_v = 0, float health_v = 0.0);
    
    /* Dtor */
    ~Player();
};

bool Player::operator==(const Player &rhs) const
{
    return (this->name == rhs.name && this->xp == rhs.xp && this->health == rhs.health);
}

Player::Player(std::string name_v, int xp_v, float health_v)
: name {name_v}, xp {xp_v}, health {health_v}
{
    std::cout << "Object created" << std::endl;
}

Player::Player(const Player &source)
: name {source.name}, health {source.health}, xp {source.xp}
{
    std::cout << "Copy created" << std::endl;
}

Player::~Player()
{
    std::cout << "Object destroyed" << std::endl;
}

int main(void)
{
    Player p0 ("Hero", 100, 15.6);
    Player p1 {p0};

    Player p2 ("Villain", 10, 111.6);
    Player p3 ("Mortal", 115, 17.6);
    Player p4 ("Spartan", 10000, 10000.5);

    std::vector<Player> vp { p2, p3, p1, p4 };

    std::vector<Player>::iterator pit = vp.begin();
    // Or auto pit

    // Need to implement 'operator=='
    pit = std::find(vp.begin(), vp.end(), p1);

    if (pit != vp.end())
    {
        std::cout << *pit << std::endl;
    } 
        

    return 0;
}

