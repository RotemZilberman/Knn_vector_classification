//Rotem Zilberman 213231418
//Ohad Langer

#include "Command8.h"

Command8::Command8(Settings &settings2) : Command(settings2) {
    this->description = "exit";
}


void Command8::execute() {
    settings.updateResume(false);
}