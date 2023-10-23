#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <memory>
#include "../inc/os_factory_unique_ptr.h"

using namespace std;

// Mock classes for the interfaces
class MockIButton : public IButton {
public:
    MOCK_METHOD(void, Press, (), (override));
};

class MockITextBox : public ITextBox {
public:
    MOCK_METHOD(void, ShowTextBox, (), (override));
};

// Test fixture
class GUIFactoryTest : public ::testing::Test {
protected:
    unique_ptr<IGUIFactory> factory;

    void SetUp() override {
        factory = nullptr;
    }
};

TEST_F(GUIFactoryTest, MacFactoryCreatesMacButtonAndTextBox) {
    factory = GUIAbstractFactory::CreateFactory("Mac");

    unique_ptr<IButton> button = factory->CreateButton();
    unique_ptr<ITextBox> textBox = factory->CreateTextBox();

    EXPECT_TRUE(dynamic_cast<MacButton*>(button.get()) != nullptr);
    EXPECT_TRUE(dynamic_cast<MacTextBox*>(textBox.get()) != nullptr);
}

TEST_F(GUIFactoryTest, WinFactoryCreatesWinButtonAndTextBox) {
    factory = GUIAbstractFactory::CreateFactory("Windows");

    unique_ptr<IButton> button = factory->CreateButton();
    unique_ptr<ITextBox> textBox = factory->CreateTextBox();

    EXPECT_TRUE(dynamic_cast<WinButton*>(button.get()) != nullptr);
    EXPECT_TRUE(dynamic_cast<WinTextBox*>(textBox.get()) != nullptr);
}

#ifdef UNIT_TEST
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif // UNIT_TEST
