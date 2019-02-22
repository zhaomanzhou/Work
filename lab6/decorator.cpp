//
// Created by zmz on 19-2-12.
//

#include "decorator.h"
#include <cmath>
#include <string>

Ceiling::Ceiling(Base *base): base(base)
{

}

double Ceiling::evaluate()
{
    return ceil(base->evaluate());
}

std::string Ceiling::stringify()
{
    return base->stringify();
}

Floor::Floor(Base *base): base(base)
{

}

double Floor::evaluate()
{
    return floor(base->evaluate());
}

std::string Floor::stringify()
{
    return base->stringify();
}

Abs::Abs(Base *base): base(base)
{

}

double Abs::evaluate()
{
    return fabs(base->evaluate());
}

std::string Abs::stringify()
{
    return base->stringify();
}

Trunc::Trunc(Base *base): base(base)
{

}

double Trunc::evaluate()
{
    return base->evaluate();
}

std::string Trunc::stringify()
{
    return std::to_string(base->evaluate());
}


Parenthesies::Parenthesies(Base *base): base(base)
{

}

double Parenthesies::evaluate()
{
    return base->evaluate();
}

std::string Parenthesies::stringify()
{
    return "(" + base->stringify() + ")";
}

