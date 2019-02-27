//
// Created by zmz on 19-2-20.
//

#ifndef LAB3_ABSTRACTFACTORY_H
#define LAB3_ABSTRACTFACTORY_H

#include "base.h"

class PrecisionOp: public Op
{
public:
    PrecisionOp(double value);

    static const int precision = 5;
    std::string stringify() override;
};


class PrecisionRand: public Rand
{
public:
    PrecisionRand();
    static const int precision = 5;
    std::string stringify() override;
};


class SciOp: public Op
{
public:
    SciOp(double value);
    std::string stringify() override;
};


class SciRand: public Rand
{
public:
    SciRand();
    std::string stringify() override;
};


class BaseFactory {
public:
    /* Constructor */
    BaseFactory();

    /* Pure Virtual Production Function */
    virtual Op* createOp(double value) = 0;
    virtual Rand* createRand() = 0;
};



class StandardDoubleFactory: public BaseFactory
{
public:
    StandardDoubleFactory();

    Op *createOp(double value) override;

    Rand *createRand() override;
};


class ScientificFactory: public BaseFactory
{
public:
    ScientificFactory();

    Op *createOp(double value) override;

    Rand *createRand() override;
};


class PrecisionFactory: public BaseFactory
{
public:
    PrecisionFactory();

    Op *createOp(double value) override;

    Rand *createRand() override;
};


#endif //LAB3_ABSTRACTFACTORY_H
