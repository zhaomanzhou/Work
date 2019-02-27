//
// Created by zmz on 19-2-27.
//

#ifndef LAB3_MENU_H
#define LAB3_MENU_H


#include <string>
#include <vector>
#include "command.hpp"




class Menu {
private:
    int history_index; // Indexes which command was last executed, accounting for undo and redo functions
    std::vector<Command*> history; // Holds all the commands that have been executed until now

public:
    Menu() {
        // Constructor which initializes the internal members
        history_index = -1;
    }

    std::string execute() {
        // Returns the string converted evaluation of the current command
        return std::to_string(history[history_index]->execute());
    }

    std::string stringify() {
        // Returns the stringified version of the current command
        return history[history_index]->stringify();

    }

    bool initialized() {
        // Returns if the history has an InitialCommand, which is necessary to start the calculation
        return history_index != -1;
    }


    void add_command(Command* cmd) {
        // Adds a command to the history (does not execute it), this may require removal of some other commands depending on where history_index is
        history_index++;
        if(history_index == history.size())
        {
            history.push_back(cmd);
        }else {
            history[history_index] = cmd;
        }

    }

    Command* get_command() {
        // Returns the command that the history_index is currently referring to
        return history[history_index];
    }

    void undo() {
        // Move back one command (does not execute it) if there is a command to undo
        if(history_index > -1)
        {
            history_index--;
        }
    }

    void redo() {
        // Moves forward one command (does not execute it) if there is a command to redo
        if(history_index < history.size()-1)
            history_index++;
    }
};


#endif //LAB3_MENU_H
