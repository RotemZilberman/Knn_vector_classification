//
// Created by ohadl on 1/15/2023.
//
#include <iostream>
#include "DefaultIO.h"
#ifndef UNTITLED12_COMMAND_H
#define UNTITLED12_COMMAND_H
#include "Settings.h"
#include "Helper.h"
#include "MathVector.h"
#include "KNN.h"

//Rotem Zilberman 213231418
//Ohad Langer
class Command {
protected:
    std::string description;
    Settings &settings;

public:
    /**
     * constructor for Command
     * @param settings2 is the setting
     */
    Command(Settings &settings2) : settings(settings2){}
    /**
     * execute the commend
     */
    virtual void execute(){};
    /**
     * what is the description of the command
     * @return the description
     */
    std::string getDescription() {
        return description;
    }
};


#endif //UNTITLED12_COMMAND_H
