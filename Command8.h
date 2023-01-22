//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_COMMAND8_H
#define UNTITLED12_COMMAND8_H
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"

class Command8 : public Command {
public:
    Command8(Settings &settings);
    void execute() override;

};


#endif //UNTITLED12_COMMAND8_H
