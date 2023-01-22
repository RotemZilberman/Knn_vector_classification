//Rotem Zilberman 213231418
//Ohad Langer

#include "Settings.h"

Settings::Settings(DefaultIO &io1) : math("AUC"),io(io1) {
    init_collections();
    k = 5;
    wasUploaded = false;
    resume = true;
    wasClassed = false;
}

DefaultIO &Settings::getDefaultIO() {
    return io;
}

std::string Settings::getKNNParam() {
    return "The current KNN parameters are: K = " + std::to_string(k) + ", distance metric = " + math.getName();
}

void Settings::setK(int newK) {
    k = newK;
}

int Settings::getK() {
    return k;
}

void Settings::setDistance(std::string dis) {
    math.SetDistanceType(dis);
}

void Settings::init_collections() {
    classified = ClassifiedCollection();
    unclassified = UnclassifiedCollection();
    result = ClassifiedCollection();
}

void Settings::push_back_unclass(std::vector<double> vec) {
    unclassified.push_back(vec);
}

void Settings::push_back_class(ClassifiedVector vec) {
    classified.push_back(vec);
}

void Settings::push_back_result(ClassifiedVector vec) {
    result.push_back(vec);
}

void Settings::updateLoaded(bool loaded) {
    wasUploaded = loaded;
}

void Settings::updateResume(bool res) {
    resume = res;
}

void Settings::updateClassified(bool classed) {
    wasClassed = classed;
}

bool Settings::getLoaded() {
    return wasUploaded;
}

bool Settings::getResume() {
    return resume;
}

bool Settings::getClassified() {
    return wasClassed;
}

UnclassifiedCollection Settings::get_unclass() {
    return unclassified;
}

ClassifiedCollection Settings::get_classified() {
    return classified;
}

ClassifiedCollection Settings::get_result() {
    return result;
}

MathVector Settings::getMath() {
    return math;
}