//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_CANBERRADISTANCE_H
#define ADVANCED_PROGRAMIN_PART2_CANBERRADISTANCE_H
#include <iostream>
#include <vector>
#include "cmath"
#include "AbstractMeasurer.h"
#include <stdexcept>

class CanberraDistance : public AbstractMeasurer{
public:
    double getDistance (std::vector<double>&first,std::vector<double> &second) override;

    std::string getName () override;
};
#endif //ADVANCED_PROGRAMIN_PART2_CANBERRADISTANCE_H
