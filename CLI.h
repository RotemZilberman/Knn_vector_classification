//
// Created by ohadl on 1/15/2023.
//

#ifndef UNTITLED12_CLI_H
#define UNTITLED12_CLI_H
#include <iostream>
#include "Command.h"
#include "Command1.h"
#include "Command2.h"
#include "Command3.h"
#include "Command4.h"
#include "Command5.h"
#include "Command8.h"
//Rotem Zilberman 213231418
//Ohad Langer
class CLI : public std::vector<Command*>{
private:
    Settings settings;

public:
    /**
     * this is constructor for the CLI class
     * @param io is the io for the class
     */
    CLI(DefaultIO &io);
    /**
     *
     * @return the menu
     */
    std::string getMenu();
    /**
     * start the function
     */
    void start();
};


#endif //UNTITLED12_CLI_H
