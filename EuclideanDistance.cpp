#include "EuclideanDistance.h"

//Rotem Zilberman 213231418
//Ohad Langer

double EuclideanDistance::getDistance(std::vector<double> &first, std::vector<double> &second) {
    if(first.size() != second.size()){
        throw std::invalid_argument("vectors is not with the same length");
    }
    double sum = 0;
    for (int i = 0; i < first.size(); i++) {
        sum += pow(first[i]-second[i],2);
    }
    return sqrt(sum);
}

std::string EuclideanDistance::getName() {
    return "AUC";
}
