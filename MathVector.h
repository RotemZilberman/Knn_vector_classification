//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_MATHVECTOR_H
#define ADVANCED_PROGRAMIN_PART2_MATHVECTOR_H

#include <iostream>
#include <vector>
#include "cmath"
#include "AbstractMeasurer.h"
#include <stdexcept>
#include <map>
#include "EuclideanDistance.h"
#include "ChebyshevDistance.h"
#include "CanberraDistance.h"
#include "MinkowskiDistance.h"
#include "ManhattanDistance.h"

class MathVector {
private:
    AbstractMeasurer *method;
    std::map<std::string, AbstractMeasurer *> MeasurerMethods;
public:
    /**
     * is the MathVector constructor
     * @param DistanceType is the DistanceType
     */
    MathVector(std::string &DistanceType);

    /**
    * is the MathVector constructor
    * @param DistanceType is the DistanceType
    */
    MathVector(std::string DistanceType);

    /**
     * changing the DistanceType
     * @param DistanceType is the new DistanceType
     */
    void SetDistanceType(std::string &DistanceType);

    /**
     * return the distance
     * @param first is the first vector
     * @param second is the second vector
     * @return the distance
     */
    double GetDistance(std::vector<double> &first, std::vector<double> &second) const;

    /**
    * return the name of the math
    * @return the name of the math
    */
    std::string getName();
};
#endif //ADVANCED_PROGRAMIN_PART2_MATHVECTOR_H
