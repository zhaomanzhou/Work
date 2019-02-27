#include "gtest/gtest.h"
#include "AbstractFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(TestAbstreactFactory, TestSciOp)
{
    SciOp sop1(12000);
    ASSERT_EQ("1.200000e+04", sop1.stringify());

    SciOp sop2(0.00034);
    ASSERT_EQ("3.400000e-04", sop2.stringify());
}



TEST(TestAbstreactFactory, TestSciRand)
{
    SciRand sr1;
    double v1 = sr1.evaluate();
    std::stringstream ss;
    ss<<std::scientific<<v1;
    std::string result;
    ss>>result;
    ASSERT_EQ(result, sr1.stringify());
}

TEST(TestAbstreactFactory, TestPrecisionOp)
{
    PrecisionOp pop1(12.2);
    ASSERT_EQ(pop1.stringify(), "12.2");

    PrecisionOp pop2(12.2111222);
    ASSERT_EQ(pop2.stringify(), "12.211");
}



TEST(TestAbstreactFactory, PrecisionRand)
{
    PrecisionRand prd;
    double v1 = prd.evaluate();
    std::stringstream ss;
    ss<<std::setprecision(PrecisionRand::precision)<<v1;
    std::string result;
    ss>>result;
    ASSERT_EQ(result, prd.stringify());
}

TEST(TestAbstractFactory, TestPrecisionFactory)
{
    BaseFactory* factory;
    factory = new PrecisionFactory();
    Op *op1 = factory->createOp(12.4757727);
    Op *op2 = factory->createOp(100);
    Mult m(op1, op2);
    ASSERT_EQ(m.stringify(), "( 12.476 * 100 )");

}

TEST(TestAbstractFactory, TestScientificFactory)
{
    BaseFactory* factory;
    factory = new ScientificFactory();
    Op *op1 = factory->createOp(12.4757727);
    Op *op2 = factory->createOp(100);
    Mult m(op1, op2);
    ASSERT_EQ(m.stringify(), "( 1.247577e+01 * 1.000000e+02 )");

}

TEST(TestAbstractFactory, TestStandardDoubleFactory)
{
    BaseFactory* factory;
    factory = new StandardDoubleFactory();
    Op *op1 = factory->createOp(12.4757727);
    Op *op2 = factory->createOp(100);
    Mult m(op1, op2);
    ASSERT_EQ(m.stringify(), "( 12.475773 * 100.000000 )");

}