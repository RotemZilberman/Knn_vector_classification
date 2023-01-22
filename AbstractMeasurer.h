//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_ABSTRACTMEASURER_H
#define ADVANCED_PROGRAMIN_PART2_ABSTRACTMEASURER_H

#include <iostream>
#include <vector>
#include "cmath"
#include <stdexcept>

class AbstractMeasurer {
public:
    /**
     * return the distance  for 2 double
     * @param first is the first vector
     * @param second is the sec vector
     * @return the distance
     */
    virtual double getDistance (std::vector<double>&first,std::vector<double> &second) = 0;

    /**
    * return the name  for math
    * @return the name
    */
    virtual std::string getName () = 0;
};
#endif //ADVANCED_PROGRAMIN_PART2_ABSTRACTMEASURER_H
