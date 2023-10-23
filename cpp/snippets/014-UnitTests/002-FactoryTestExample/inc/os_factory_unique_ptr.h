#include <string>
#include <memory>

#define UNIT_TEST

/* Button Definition */
class IButton
{
public:
  virtual void Press() = 0;
};

class MacButton : public IButton
{
public:
  void Press() override;
};

class WinButton : public IButton
{
public:
  void Press() override;
};

/* TextBox Definition */
class ITextBox
{
public:
  virtual void ShowTextBox() = 0;
};

class MacTextBox : public ITextBox
{
public:
  void ShowTextBox() override;
};

class WinTextBox : public ITextBox
{
public:
  void ShowTextBox() override;
};

/* Factories Definition */
class IGUIFactory
{
public:
  virtual std::unique_ptr<IButton> CreateButton() = 0;
  virtual std::unique_ptr<ITextBox> CreateTextBox() = 0;
};

class MacFactory : public IGUIFactory
{
public:
  std::unique_ptr<IButton> CreateButton() override;
  std::unique_ptr<ITextBox> CreateTextBox() override;
};

class WinFactory : public IGUIFactory
{
public:
  std::unique_ptr<IButton> CreateButton() override;
  std::unique_ptr<ITextBox> CreateTextBox() override;
};

class GUIAbstractFactory 
{
public:
  static std::unique_ptr<IGUIFactory> CreateFactory(std::string os_type);
};
