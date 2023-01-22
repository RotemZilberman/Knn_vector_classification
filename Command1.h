//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_COMMAND1_H
#define UNTITLED12_COMMAND1_H
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"
#include "Helper.h"

class Command1 : public Command {
public:
    Command1(Settings &settings);
    void execute() override;
};


#endif //UNTITLED12_COMMAND1_H
