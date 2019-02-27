#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "base.h"

class Command {
protected:
    Base* root;

public:
    Command() { this->root = nullptr; }
    double execute() { return root->evaluate(); }
    std::string stringify() { return root->stringify(); }
    Base* get_root() { return root; }
};



class InitialCommand: public Command{
public:
    InitialCommand(Base* base) : Command() {
        root = base;

    }
};

class AddCommand: public Command{
public:
    AddCommand(Command* cmd, Base* base) : Command() {
        root = new Add(cmd->get_root(), base);
    }
};

class SubCommand: public Command{
public:
    SubCommand(Command* cmd, Base* base) : Command() {
        root = new Sub(cmd->get_root(), base);
    }
};


class MultCommand: public Command{
public:
    MultCommand(Command* cmd, Base* base) : Command() {
        root = new Mult(cmd->get_root(), base);
    }
};

class DivCommand: public Command{
public:
    DivCommand(Command* cmd, Base* base) : Command() {
        root = new Div(cmd->get_root(), base);
    }
};

class PowCommand: public Command{
public:
    PowCommand(Command* cmd, Base* base) : Command() {
        root = new Pow(cmd->get_root(), base);
    }
};

#endif