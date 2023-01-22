//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_COMMAND2_H
#define UNTITLED12_COMMAND2_H
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"

class Command2 : public Command {
public:
    Command2(Settings &settings);
    void execute() override;
};


#endif //UNTITLED12_COMMAND2_H
