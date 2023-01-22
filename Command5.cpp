//Rotem Zilberman 213231418
//Ohad Langer

#include "Command5.h"
#include <iostream>

Command5::Command5(Settings &settings2) : Command(settings2) {
    this->description = "download results";
}

void Command5::execute() {
    DefaultIO &io = settings.getDefaultIO();
    if (!settings.getLoaded()) {
        io.write("please upload data\n");
        return;
    }
    if (!settings.getClassified()) {
        io.write("please classify the data\n");
        return;
    }
    io.write("Please enter a path.\n\r\n");
    std::string input = io.read();
    std::string send = "download " + input + "\n";
    ClassifiedCollection result = settings.get_result();
    int index = 1;
    for (ClassifiedVector vector : result) {
        send += std::to_string(index++) + "," + vector.GetClass() + "\n";
    }
    send+="\r\n";
    io.write(send);
    input = io.read();
}