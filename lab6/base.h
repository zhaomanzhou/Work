//
// Created by zmz on 19-1-29.
//

#ifndef LAB3_BASE_H
#define LAB3_BASE_H

#include <string>

class Base {
public:
/* Constructors */
    Base() { };
/* Pure Virtual Functions */
    virtual double evaluate() = 0;
    virtual std::string stringify() = 0;
};


class Op: public Base
{
public:
    Op(double value);

    double evaluate() override;

    std::string stringify() override;

protected:
    double value;
};

class Rand: public Base
{
public:
    Rand();

    double evaluate() override;

    std::string stringify() override;

protected:
    double value;
};

class Mult: public Base
{
public:
    Mult(Base *left, Base *right);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* left;
    Base* right;

};

class Div: public Base
{
public:
    Div(Base *left, Base *right);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* left;
    Base* right;
};

class Add: public Base
{
public:
    Add(Base *left, Base *right);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* left;
    Base* right;
};


class Sub: public Base
{
public:
    Sub(Base *left, Base *right);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* left;
    Base* right;
};


class Pow: public Base
{
public:
    Pow(Base *left, Base *right);

    double evaluate() override;

    std::string stringify() override;

private:
    Base* left;
    Base* right;
};




#endif //LAB3_BASE_H
