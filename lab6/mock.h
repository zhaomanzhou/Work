//
// Created by zmz on 19-1-30.
//

#ifndef LAB3_MOCK_H
#define LAB3_MOCK_H

#include "base.h"

class SevenOpMock: public Base
{
public:
    double evaluate() override
    {
        return 7.5;
    }

    std::string stringify() override
    {
        return "7.5";
    }
};

class TwentyOpMock: public Base
{
public:
    double evaluate() override
    {
        return 20;
    }

    std::string stringify() override
    {
        return "20";
    }
};


class FiftyOpMock: public Base
{
public:
    double evaluate() override
    {
        return 50;
    }

    std::string stringify() override
    {
        return "50";
    }
};


class TwoOpMock: public Base
{
public:
    double evaluate() override
    {
        return 2;
    }

    std::string stringify() override
    {
        return "2";
    }
};



class FourOpMock: public Base
{
public:
    double evaluate() override
    {
        return 4;
    }

    std::string stringify() override
    {
        return "4";
    }
};

#endif //LAB3_MOCK_H
