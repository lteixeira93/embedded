#include <iostream>
#include <memory>

using namespace std;

/* Button Implementation */
class IButton
{
public:
  virtual void Press() = 0;
};

class MacButton : public IButton
{
public:
  void Press() override
  {
    cout << "Pressing MacButton\n";
  }
};

class WinButton : public IButton
{
public:
  void Press() override
  {
    cout << "Pressing WinButton\n";
  }
};

/* TextBox Implementation */
class ITextBox
{
public:
  virtual void ShowTextBox() = 0;
};

class MacTextBox : public ITextBox
{
public:
  void ShowTextBox() override
  {
    cout << "Showing MacTextBox\n";
  }
};

class WinTextBox : public ITextBox
{
public:
  void ShowTextBox() override
  {
    cout << "Showing WinTextBox\n";
  }
};

/* Factories Implementation */
class IGUIFactory
{
public:
  virtual unique_ptr<IButton> CreateButton() = 0;
  virtual unique_ptr<ITextBox> CreateTextBox() = 0;
};

class MacFactory : public IGUIFactory
{
public:
  unique_ptr<IButton> CreateButton() override
  {
    return make_unique<MacButton>();
  }

  unique_ptr<ITextBox> CreateTextBox() override
  {
    return make_unique<MacTextBox>();
  }

};

class WinFactory : public IGUIFactory
{
public:
  unique_ptr<IButton> CreateButton() override
  {
    return make_unique<WinButton>();
  }

  unique_ptr<ITextBox> CreateTextBox() override
  {
    return make_unique<WinTextBox>();
  }

};

class GUIAbstractFactory 
{
public:
  static unique_ptr<IGUIFactory> CreateFactory(std::string os_type)
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
};

int main(void)
{
  /* Client Side Implementation */
  string os_type;
  cout << "Enter OS type (Windows or Mac (Default)): " << endl; 
  cin >> os_type;

  unique_ptr<IGUIFactory> fact = GUIAbstractFactory::CreateFactory(os_type);
  fact->CreateButton()->Press();
  fact->CreateTextBox()->ShowTextBox();

  return 0;
}
