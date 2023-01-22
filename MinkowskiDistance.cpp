//Rotem Zilberman 213231418
//Ohad Langer
#define p 2
#include "MinkowskiDistance.h"

double MinkowskiDistance::getDistance(std::vector<double> &first, std::vector<double> &second) {
    if(first.size() != second.size()){
        throw std::invalid_argument("vectors is not with the same length");
    }
    double sum = 0;
    for (int i = 0; i < first.size(); i++) {
        sum += pow(std::abs(first[i]-second[i]),p);
    }
    return pow(sum,(double)1/p);
}

std::string MinkowskiDistance::getName() {
    return "MIN";
}
