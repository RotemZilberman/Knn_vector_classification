//Rotem Zilberman 213231418
//Ohad Langer

#include "ClassifiedVector.h"


ClassifiedVector::ClassifiedVector(double arr[], int size, std::string clas) : std::vector<double>(arr, arr + size) {
    this->classification = std::move(clas);
}

ClassifiedVector::ClassifiedVector(std::vector<double> v, std::string clas) : std::vector<double>(std::move(v)) { this->classification = std::move(clas); }

std::string ClassifiedVector::GetClass() { return this->classification; }