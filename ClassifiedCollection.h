//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_CLASSIFIEDCOLLECTION_H
#define ADVANCED_PROGRAMIN_PART2_CLASSIFIEDCOLLECTION_H

#include "TestFinding.h"
#include "ClassifiedVector.h"
#include "MathVector.h"
/**
 * this is the ClassifiedCollection class
 */
class ClassifiedCollection : public std::vector<ClassifiedVector>{
    public:
        ClassifiedCollection();
        /**
         * return the std::vector<TestFinding> result for the vector and the math
         * @param vector is the vector
         * @param mathVector is the math
         * @return the std::vector<TestFinding> result for the vector and the math
         */
        std::vector<TestFinding> result(std::vector<double> vector, MathVector mathVector);
};


#endif //ADVANCED_PROGRAMIN_PART2_CLASSIFIEDCOLLECTION_H
