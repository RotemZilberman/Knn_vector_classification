//Rotem Zilberman 213231418
//Ohad Langer

#include "Command3.h"
#include <iostream>

Command3::Command3(Settings &settings2) : Command(settings2) {
    this->description = "classify data";
}


void Command3::execute() {
    DefaultIO &io = settings.getDefaultIO();
    if (!settings.getLoaded()) {
        io.write("please upload data\n");
        return;
    }
    if (settings.getClassified()) {
        return;
    }
    ClassifiedCollection classified = settings.get_classified();
    UnclassifiedCollection unclassified = settings.get_unclass();
    KNN algorithm(classified);
    try {
        for (std::vector<double> curr: unclassified) {
            std::string classification = algorithm.classification(curr, settings.getMath(), settings.getK());
            settings.push_back_result(ClassifiedVector(curr, classification));
        }
    }
    catch (std::exception e){
        io.write("invalid input\n");
        return;
    }
    io.write("classifying data complete\n");
    settings.updateClassified(true);
}