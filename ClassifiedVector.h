//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_CLASSVECTOR_H
#define ADVANCED_PROGRAMIN_PART2_CLASSVECTOR_H

#include <vector>
#include <iostream>
#include <utility>
#include <vector>
/**
 * this is the ClassifiedVector class
 */
class ClassifiedVector : public std::vector<double>{
    private:
        std::string classification;

    public:
        ClassifiedVector(double arr[], int size, std::string clas);
        /**
         * reutrn the ClassifiedVector
         * @param v is vector
         * @param clas is the classification
         */
        ClassifiedVector(std::vector<double> v, std::string clas);
        /**
         * return the classification
         * @return the classification
         */
        std::string GetClass();
};


#endif //ADVANCED_PROGRAMIN_PART2_CLASSVECTOR_H
