//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART4_STANDARDIO_H
#define ADVANCED_PROGRAMIN_PART4_STANDARDIO_H


#include "DefaultIO.h"
#include <iostream>

class StandardIO : public DefaultIO{
    std::string read() override;
    void write(std::string) override;
};


#endif //ADVANCED_PROGRAMIN_PART4_STANDARDIO_H
