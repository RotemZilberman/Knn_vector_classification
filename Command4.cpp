//Rotem Zilberman 213231418
//Ohad Langer

#include "Command4.h"
#include <iostream>

Command4::Command4(Settings &settings2) : Command(settings2){
    this->description = "display results";
}


void Command4::execute() {
    DefaultIO &io = settings.getDefaultIO();
    if (!settings.getLoaded()) {
        io.write("please upload data\n");
        return;
    }
    if (!settings.getClassified()) {
        io.write("please classify the data\n");
        return;
    }
    ClassifiedCollection result = settings.get_result();
    std::string output;
    int index = 1;
    for (ClassifiedVector vector : result) {
        output += std::to_string(index++) + "\t" + vector.GetClass() + "\n";
    }
    output += "Done.\n";
    io.write(output);
}