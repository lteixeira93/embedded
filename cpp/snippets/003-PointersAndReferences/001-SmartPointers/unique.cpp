#include <iostream>
#include <memory>

int main(void)
{
    /* Creating a unique_ptr */
    std::unique_ptr<int> p1(new int(5));
    std::unique_ptr<int> p2 = std::make_unique<int>(10);
    std::cout << *p1 << ", " << *p2 << std::endl;

    /* Transferring Ownership */
    std::unique_ptr<int> p3(new int(5));
    std::unique_ptr<int> p4 = std::move(p3); // Ownership is transferred from p1 to p2

    if (p3) {
        std::cout << "p3 owns the object" << std::endl;
    } else if (p4) {
        std::cout << "p4 owns the object" << std::endl;
    }

    return 0;
}