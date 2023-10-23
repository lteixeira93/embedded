/* Compile: g++ -std=c++14 src/*.cpp -I inc/ -o run */
#include <iostream>
#include <memory>
#include "../inc/os_factory_unique_ptr.h"

#ifndef UNIT_TEST
int main(void)
{
  /* Client Side Implementation */
  std::string os_type;
  std::cout << "Enter OS type (Windows or Mac (Default)): " << std::endl; 
  std::cin >> os_type;

  std::unique_ptr<IGUIFactory> fact = GUIAbstractFactory::CreateFactory(os_type);
  fact->CreateButton()->Press();
  fact->CreateTextBox()->ShowTextBox();

  return 0;
}
#endif // UNIT_TEST