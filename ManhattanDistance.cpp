#include "ManhattanDistance.h"

//Rotem Zilberman 213231418
//Ohad Langer

double ManhattanDistance::getDistance(std::vector<double> &first, std::vector<double> &second) {
    if(first.size() != second.size()){
        throw std::invalid_argument("vectors is not with the same length");
    }
    double sum = 0;
    for (int i = 0; i < first.size(); i++) {
        sum += std::abs(first[i]-second[i]);
    }
    return sum;
}

std::string ManhattanDistance::getName() {
    return "MAN";
}
