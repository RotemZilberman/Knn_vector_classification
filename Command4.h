//Rotem Zilberman 213231418
//Ohad Langer

#ifndef UNTITLED12_COMMAND4_H
#define UNTITLED12_COMMAND4_H
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"

class Command4 : public Command {
public:
    Command4(Settings &settings);
    void execute() override;
};


#endif //UNTITLED12_COMMAND4_H
