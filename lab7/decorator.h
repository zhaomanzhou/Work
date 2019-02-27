//
// Created by zmz on 19-2-12.
//

#ifndef LAB3_DECORATOR_H
#define LAB3_DECORATOR_H

#include <string>
#include "base.h"

class decorator
{
public:
    decorator(){};
    virtual double evaluate() = 0;
    virtual std::string stringify() = 0;

};

class Ceiling : public decorator
{
public:
    Ceiling(Base* base);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* base;
};




class Floor : public decorator
{
public:
    Floor(Base* base);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* base;
};

class Abs : public decorator
{
public:
    Abs(Base* base);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* base;
};


class Trunc : public decorator
{
public:
    Trunc(Base* base);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* base;
};


class Parenthesies : public decorator
{
public:
    Parenthesies(Base* base);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* base;
};

#endif //LAB3_DECORATOR_H
