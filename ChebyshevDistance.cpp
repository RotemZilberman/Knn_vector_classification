#include "ChebyshevDistance.h"

//Rotem Zilberman 213231418
//Ohad Langer

double ChebyshevDistance::getDistance(std::vector<double> &first, std::vector<double> &second) {
    if(first.size() != second.size()){
        throw std::invalid_argument("vectors is not with the same length");
    }
    double maximum = 0;
    for (int i = 0; i < first.size(); i++) {
        maximum = fmax(maximum, std::abs(first[i]-second[i]));
    }
    return maximum;
}

std::string ChebyshevDistance::getName() {
    return "CHB";
}
