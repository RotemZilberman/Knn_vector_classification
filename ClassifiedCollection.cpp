//Rotem Zilberman 213231418
//Ohad Langer

#include "ClassifiedCollection.h"

ClassifiedCollection::ClassifiedCollection() : vector<ClassifiedVector>() {}

std::vector<TestFinding> ClassifiedCollection::result(std::vector<double> vector, MathVector math) {
    std::vector<TestFinding> results;
    for (ClassifiedVector temp : *this) {
        results.push_back(TestFinding(math.GetDistance(vector, temp), temp.GetClass()));
    }
    return results;
}