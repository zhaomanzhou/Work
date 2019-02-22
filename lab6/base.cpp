//
// Created by zmz on 19-1-29.
//

#include "base.h"
#include <ctime>
#include <cmath>


Op::Op(double value) : value(value)
{}

double Op::evaluate()
{
    return this->value;
}

std::string Op::stringify()
{
    return std::to_string(value);
}






Rand::Rand()
{
    srand(unsigned(time(NULL)));
    value = rand()%100;
}

double Rand::evaluate()
{
    return value;
}

std::string Rand::stringify()
{
    return std::to_string(value);
}






Mult::Mult(Base *left, Base *right) : left(left), right(right)
{}


double Mult::evaluate()
{
    return left->evaluate()*right->evaluate();
}

std::string Mult::stringify()
{
    return "( " + left->stringify() + " * " + right->stringify() + " )";
}





Div::Div(Base *left, Base *right): left(left), right(right)
{

}

double Div::evaluate()
{
    return left->evaluate()/right->evaluate();
}

std::string Div::stringify()
{
    return "( " + left->stringify() + " / " + right->stringify() + " )";
}








Add::Add(Base *left, Base *right): left(left), right(right)
{

}

double Add::evaluate()
{
    return left->evaluate()+right->evaluate();
}

std::string Add::stringify()
{
    return "( " + left->stringify() + " + " + right->stringify() + " )";
}







Sub::Sub(Base *left, Base *right): left(left), right(right)
{

}

double Sub::evaluate()
{
    return left->evaluate()-right->evaluate();
}

std::string Sub::stringify()
{
    return "( " + left->stringify() + " - " + right->stringify() + " )";
}








Pow::Pow(Base *left, Base *right): left(left), right(right)
{

}

double Pow::evaluate()
{
    return pow(left->evaluate(), right->evaluate());
}

std::string Pow::stringify()
{
    return "( " + left->stringify() + " ** " + right->stringify() + " )";
}






