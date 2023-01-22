//Rotem Zilberman 213231418
//Ohad Langer

#include "MathVector.h"

MathVector::MathVector(std::string &DistanceType){
    MeasurerMethods["MAN"] = new ManhattanDistance();
    MeasurerMethods["AUC"] = new EuclideanDistance();
    MeasurerMethods["CHB"] = new ChebyshevDistance();
    MeasurerMethods["CAN"] = new CanberraDistance();
    MeasurerMethods["MIN"] = new MinkowskiDistance();
    method = MeasurerMethods[DistanceType];
    if(method == nullptr){
        method = MeasurerMethods["AUC"];
        throw std::invalid_argument("invalid input");
    }
}

void MathVector::SetDistanceType(std::string &DistanceType) {
    std::string &nameBack = DistanceType;
    method = MeasurerMethods[DistanceType];
    if(method == nullptr){
        method = MeasurerMethods[nameBack];
        throw std::invalid_argument("invalid input");
    }
}

double MathVector::GetDistance(std::vector<double> &first, std::vector<double> &second) const {
    return method->getDistance(first,second);
}

MathVector::MathVector(std::string DistanceType) {
    MeasurerMethods["MAN"] = new ManhattanDistance();
    MeasurerMethods["AUC"] = new EuclideanDistance();
    MeasurerMethods["CHB"] = new ChebyshevDistance();
    MeasurerMethods["CAN"] = new CanberraDistance();
    MeasurerMethods["MIN"] = new MinkowskiDistance();
    method = MeasurerMethods[DistanceType];
    if(method == nullptr){
        throw std::invalid_argument("invalid input");
    }
}

std::string MathVector::getName() {
    return method->getName();
}
