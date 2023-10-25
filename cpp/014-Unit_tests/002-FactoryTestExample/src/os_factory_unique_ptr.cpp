#include <iostream>
#include <memory>
#include "../inc/os_factory_unique_ptr.h"

using namespace std;

/* Button Implementation */

void MacButton::Press()
{
  cout << "Pressing MacButton\n";
}

void WinButton::Press()
{
  cout << "Pressing WinButton\n";
}

/* TextBox Implementation */
void MacTextBox::ShowTextBox()
{
  cout << "Showing MacTextBox\n";
}

void WinTextBox::ShowTextBox()
{
  cout << "Showing WinTextBox\n";
}

/* Factories Implementation */
std::unique_ptr<IButton> MacFactory::CreateButton()
{
  return make_unique<MacButton>();
}

std::unique_ptr<ITextBox> MacFactory::CreateTextBox()
{
  return make_unique<MacTextBox>();
}

std::unique_ptr<IButton> WinFactory::CreateButton()
{
  return make_unique<WinButton>();
}

std::unique_ptr<ITextBox> WinFactory::CreateTextBox()
{
  return make_unique<WinTextBox>();
}

std::unique_ptr<IGUIFactory> GUIAbstractFactory::CreateFactory(std::string os_type)
{
  if(os_type == "Windows")
  {
    return make_unique<WinFactory>();
  }
  else if(os_type == "Mac")
  {
    return make_unique<MacFactory>();
  }
  return make_unique<MacFactory>();
}
