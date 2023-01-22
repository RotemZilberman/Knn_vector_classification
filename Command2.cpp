//Rotem Zilberman 213231418
//Ohad Langer

#include "Command2.h"
#include <iostream>

Command2::Command2(Settings &settings2) : Command(settings2) {
    this->description = "algorithm settings";
}

void Command2::execute() {
    DefaultIO &io = settings.getDefaultIO();
    io.write(settings.getKNNParam() + "\n\r\n");
    std::string input = io.read();
    std::string method, problem;
    std::string mathBack = settings.getMath().getName();
    int kBack = settings.getK();
    if(input == ""){
        return;
    }
    try {
        int space = input.rfind(" ");
        try {
            method = input.substr(space+1, input.length());
            settings.setDistance(method);
        }
        catch (std::exception exc){
            problem = "invalid value for metric\n";
        }
        try {
            std::string sub = input.substr(0, space);
            double DouK = Helper::StringToDouble(sub);
            if(DouK == floor((DouK))) {
                settings.setK(floor(DouK));
            }
            else{
                throw std::invalid_argument("invalid input");
            }
        }
        catch (std::exception exc){
            problem = problem + "invalid value for k\n";
        }
        if (problem != "") {
            throw std::invalid_argument(problem);
        }
    }
    catch (std::invalid_argument exc) {
        settings.setDistance(mathBack);
        settings.setK(kBack);
        io.write(problem);
    }
}