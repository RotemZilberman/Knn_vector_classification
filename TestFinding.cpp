#include "TestFinding.h"
//Rotem Zilberman 213231418
//Ohad Langer
TestFinding::TestFinding(double distance, std::string classification): distance(distance), classification(std::move(classification)) {
}

double TestFinding::GetDistance() const {
    return this->distance;
}

std::string TestFinding::GetClassification() const {
        return this->classification;
}