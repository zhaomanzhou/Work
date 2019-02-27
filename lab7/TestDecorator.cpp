#include <iostream>
#include <gtest/gtest.h>
#include "base.h"
#include "decorator.h"

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TestCeil, TestEvaluate1)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2.2);
    Sub* d = new Sub(add, two);
    Ceiling* c = new Ceiling(d);
    ASSERT_EQ(c->evaluate(), 29);
}

TEST(TestCeil, TestEvaluate2)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2.8);
    Sub* d = new Sub(add, two);
    Ceiling* c = new Ceiling(d);
    ASSERT_EQ(c->evaluate(), 29);
}

TEST(TestFloor, TestFloor1)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2.2);
    Sub* d = new Sub(add, two);
    Floor* c = new Floor(d);
    ASSERT_EQ(c->evaluate(), 28);
}

TEST(TestFloor, TestFloor2)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2.8);
    Sub* d = new Sub(add, two);
    Floor* c = new Floor(d);
    ASSERT_EQ(c->evaluate(), 28);
}

TEST(TestAbs, TestAbs1)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2);
    Sub* d = new Sub(add, two);
    Abs* c = new Abs(d);
    ASSERT_EQ(c->evaluate(), 29);
}


TEST(TestAbs, TestAbs2)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2);
    Sub* d = new Sub(two, add);
    Abs* c = new Abs(d);
    ASSERT_EQ(c->evaluate(), 29);
}

TEST(TestTrunc, TestTrunc)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2);
    Sub* d = new Sub(add, two);
    Trunc* c = new Trunc(d);
    ASSERT_EQ(c->stringify(), "29.000000");
}

TEST(TestParen, TestParen)
{
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* m = new Mult(seven, four);
    Op* three = new Op(3);
    Add* add = new Add(three, m);
    Op* two = new Op(2.2);
    Sub* d = new Sub(add, two);
    Parenthesies* c = new Parenthesies(d);
    ASSERT_EQ(c->stringify(), "(( ( 3.000000 + ( 7.000000 * 4.000000 ) ) - 2.200000 ))");
}

