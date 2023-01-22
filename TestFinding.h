//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_TESTFINDING_H
#define ADVANCED_PROGRAMIN_PART2_TESTFINDING_H

#include <iostream>
#include <utility>
#include "cmath"

class TestFinding{
private:
    double distance;
    std::string classification;
public:
    /**
     * is the TestFinding constructor
     * @param distance is the distance
     * @param classification is the classification
     */
    TestFinding(double distance, std::string classification);
    /**
     * return the distance
     * @return the distance
     */
    double GetDistance() const;
    /**
     * return the classification
     * @return the classification
     */
    std::string GetClassification() const;
};

#endif //ADVANCED_PROGRAMIN_PART2_TESTFINDING_H
