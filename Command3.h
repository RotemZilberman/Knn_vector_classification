//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_COMMAND3_H
#define UNTITLED12_COMMAND3_H
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"

class Command3 : public Command {
public:
    Command3(Settings &settings);
    void execute() override;
};


#endif //UNTITLED12_COMMAND3_H
