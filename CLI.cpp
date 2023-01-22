//Rotem Zilberman 213231418
//Ohad Langer

#include "CLI.h"

CLI::CLI(DefaultIO &io) : settings(io){
    push_back(new Command1(settings));
    push_back(new Command2(settings));
    push_back(new Command3(settings));
    push_back(new Command4(settings));
    push_back(new Command5(settings));
    push_back(new Command8(settings));
}

std::string CLI::getMenu() {
    std::string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int index = 1;
    for (Command *command : *this) {
        if (index < 6) {
            menu += std::to_string(index++) + ". " + command->getDescription() + "\n";
        }
        else {
            menu += "8. " + command->getDescription() + "\n\r\n";
        }
    }
    return menu;
}

void CLI::start() {
    DefaultIO &io = settings.getDefaultIO();
    int commandNum;
    while (settings.getResume()) {
        io.write(getMenu());
        std::string input = io.read();
        try {
            commandNum = std::stoi(input);
            if (std::to_string(commandNum) != input || !((commandNum > 0 && commandNum <= 5) || commandNum == 8)) {
                throw std::exception();
            }
        }
        catch (std::exception exc) {
            io.write("invalid input\n");
            continue;
        }
        if (commandNum == 8) {
            this->at(5)->execute();
            continue;
        }
        try {
            this->at(commandNum - 1)->execute();
        }
        catch (std::exception e){
            this->at(5)->execute();
        }
    }
}