//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_COMMAND5_H
#define UNTITLED12_COMMAND5_H
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"

class Command5 : public Command {
public:
    Command5(Settings &settings);
    void execute() override;
};


#endif //UNTITLED12_COMMAND5_H
