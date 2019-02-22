//
// Created by zmz on 19-1-29.
//

#include "gtest/gtest.h"
#include "base.h"
#include "mock.h"

using namespace std;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(TestOp, TestImplement)
{
    Op o(12);
    cout<<"evaluate value "<<o.evaluate()<<endl;
    cout<<"stringify value "<<o.stringify()<<endl;
    ASSERT_DOUBLE_EQ(o.evaluate(), 12);
}

TEST(TestRand, TestImplement)
{
    Rand r;
    cout<<"r value "<<r.evaluate()<<endl;
    ASSERT_EQ(r.stringify(), to_string(r.evaluate()));
}

TEST(TestMulti, TestImplement)
{
    Base* sevenOp = new SevenOpMock;
    Base* twentyOp = new TwentyOpMock;
    Mult m(sevenOp, twentyOp);
    cout<<"stringfy "<<m.stringify()<<endl;
    ASSERT_DOUBLE_EQ(m.evaluate(), 150);
}

TEST(TestDiv, TestImplement)
{
    Base* fiftyOp = new FiftyOpMock;
    Base* twentyOp = new TwentyOpMock;
    Div m(fiftyOp, twentyOp);
    cout<<"stringfy "<<m.stringify()<<endl;
    ASSERT_DOUBLE_EQ(m.evaluate(), 2.5);
}

TEST(TestAdd, TestImplement)
{
    Base* sevenOp = new SevenOpMock;
    Base* twentyOp = new TwentyOpMock;
    Add m(sevenOp, twentyOp);
    cout<<"stringfy "<<m.stringify()<<endl;
    ASSERT_DOUBLE_EQ(m.evaluate(), 27.5);
}

TEST(TestSub, TestImplement)
{
    Base* sevenOp = new SevenOpMock;
    Base* twentyOp = new TwentyOpMock;
    Sub m(twentyOp, sevenOp);
    cout<<"stringfy "<<m.stringify()<<endl;
    ASSERT_DOUBLE_EQ(m.evaluate(), 12.5);
}

TEST(TestPow, TestImplement)
{
    Base* twoOp = new TwoOpMock;
    Base* fourOp = new FourOpMock;
    Pow m(twoOp, fourOp);
    cout<<"stringfy "<<m.stringify()<<endl;
    ASSERT_DOUBLE_EQ(m.evaluate(), 16);
}


TEST(TestComplex, TestAddAndMulti)
{
    Base* twoOp = new TwoOpMock;
    Base* fourOp = new FourOpMock;
    Base* twentyOp = new TwentyOpMock;
    Pow m(twoOp, fourOp);
    Add a(&m, twentyOp);
    cout<<"stringfy "<<a.stringify()<<endl;
    ASSERT_DOUBLE_EQ(a.evaluate(), 36);
}


TEST(TestComplex, TestSubAndDiv)
{
    Base* twoOp = new TwoOpMock;
    Base* fourOp = new FourOpMock;
    Base* twentyOp = new TwentyOpMock;
    Div d(fourOp, twoOp);
    Sub s(twentyOp, &d);
    cout<<"stringfy "<<s.stringify()<<endl;
    ASSERT_DOUBLE_EQ(s.evaluate(), 18);
}







