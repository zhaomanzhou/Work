//
// Created by zmz on 19-2-20.
//
#include <sstream>
#include <iomanip>
#include "AbstractFactory.h"
#include "base.h"







std::string SciRand::stringify()
{
    std::stringstream ss;
    ss<<std::scientific<<value;
    std::string result;
    ss>>result;
    return result;
}

SciRand::SciRand() : Rand()
{

}

std::string SciOp::stringify()
{
    std::stringstream ss;
    ss<<std::scientific<<value;
    std::string result;
    ss>>result;
    return result;
}

SciOp::SciOp(double value) : Op(value)
{

}

std::string PrecisionRand::stringify()
{
    std::stringstream ss;
    ss<<std::setprecision(precision)<<value;
    std::string result;
    ss>>result;
    return result;
}

PrecisionRand::PrecisionRand() : Rand()
{

}

std::string PrecisionOp::stringify()
{
    std::stringstream ss;
    ss<<std::setprecision(precision)<<value;
    std::string result;
    ss>>result;
    return result;
}

PrecisionOp::PrecisionOp(double value) : Op(value)
{

}

BaseFactory::BaseFactory()
{

}

StandardDoubleFactory::StandardDoubleFactory() : BaseFactory()
{

}

Op *StandardDoubleFactory::createOp(double value)
{
    return new Op(value);
}

Rand *StandardDoubleFactory::createRand()
{
    return new Rand;
}

ScientificFactory::ScientificFactory() : BaseFactory()
{

}

Op *ScientificFactory::createOp(double value)
{
    return new SciOp(value);
}

Rand *ScientificFactory::createRand()
{
    return new SciRand;
}

PrecisionFactory::PrecisionFactory() : BaseFactory()
{

}

Op *PrecisionFactory::createOp(double value)
{
    return new PrecisionOp(value);
}

Rand *PrecisionFactory::createRand()
{
    return new PrecisionRand;
}
