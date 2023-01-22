//Rotem Zilberman 213231418
//Ohad Langer

#include "Command1.h"
//#include "Settings.h"
//#include "DefaultIO.h"
#include <iostream>

Command1::Command1(Settings &settings2) : Command(settings2) {
    this->description = "upload an unclassified csv data file";
}

void Command1::execute() { // order may be the other way
    settings.updateLoaded(false);
    settings.updateClassified(false);
    settings.init_collections();
    DefaultIO &io = settings.getDefaultIO();
    io.write("Please upload your local train CSV file.\n\r\n");
    std::string input = io.read();
    io.write("upload " + input + "\r\n");
    input = io.read();
    if(input == ""){
        io.write("invalid input\n");
        return;
    }
    while (input != "") { // classified vectors
        try {
            int end = input.find("\n");
            std::string curr = input.substr(0, end);
            int space = curr.rfind(",");
            std::string strVector = curr.substr(0, space);
            std::string classification = curr.substr(space+1, curr.length());
            ClassifiedVector vector = ClassifiedVector(Helper::StringToVector(strVector, ','), classification);
            settings.push_back_class(vector);
            input = input.substr(end+1, input.length());
        }
        catch (std::exception exc) {
            io.write("invalid input\n");
            return;
        }
    }
    io.write("Upload complete.\nPlease upload your local test CSV file.\n\r\n");
    input = io.read();
    io.write("upload " + input + "\r\n");
    input = io.read();
    if(input == ""){
        io.write("invalid input\n");
        return;
    }
    while (input != "") { // unclassified vectors
        int end = input.find("\n");
        std::string curr = input.substr(0, end);
        std::vector<double> vector = Helper::StringToVector(curr, ',');
        settings.push_back_unclass(vector);
        input = input.substr(end+1, input.length());
    }
    io.write("Upload complete.\n");
    settings.updateLoaded(true);
}