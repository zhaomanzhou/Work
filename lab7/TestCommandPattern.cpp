#include "gtest/gtest.h"
#include "command.hpp"
#include "Menu.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestCommand, TestInitialCommand)
{
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    ASSERT_EQ(c->stringify(), "4.000000");
    ASSERT_EQ(c->get_root(), pOp);
}


TEST(TestCommand, TestAddCommand)
{
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    Command* add = new AddCommand(c, new Op(1));
    ASSERT_DOUBLE_EQ(add->execute(), 5);

}

TEST(TestCommand, TestSubCommand)
{
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    Command* sub = new SubCommand(c, new Op(1));
    ASSERT_DOUBLE_EQ(sub->execute(), 3);
}


TEST(TestCommand, TestMultCommand)
{
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    Command* mult = new MultCommand(c, new Op(1));
    ASSERT_DOUBLE_EQ(mult->execute(), 4);
}


TEST(TestCommand, TestDivCommand)
{
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    Command* div = new DivCommand(c, new Op(2));
    ASSERT_DOUBLE_EQ(div->execute(), 2);
}

TEST(TestCommand, TestPowCommand)
{
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    Command* pow = new PowCommand(c, new Op(2));
    ASSERT_DOUBLE_EQ(pow->execute(), 16);
}

TEST(TestMenu, TestMenu)
{
    Menu* menu = new Menu;
    ASSERT_FALSE(menu->initialized());
    Op *pOp = new Op(4);
    Command* c  = new InitialCommand(pOp);
    menu->add_command(c);
    ASSERT_TRUE(menu->initialized());
    cout<<menu->execute();
    ASSERT_EQ(menu->execute(), "4.000000");
    Command* pow = new PowCommand(c, new Op(2));
    menu->add_command(pow);
    ASSERT_EQ(menu->execute(), "16.000000");
    ASSERT_EQ(menu->stringify(), "( 4.000000 ** 2.000000 )");
    menu->undo();
    ASSERT_EQ(menu->execute(), "4.000000");
    menu->redo();
    ASSERT_EQ(menu->execute(), "16.000000");




}