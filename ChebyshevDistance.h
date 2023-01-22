//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART2_CHEBYSHEVDISTANCE_H
#define ADVANCED_PROGRAMIN_PART2_CHEBYSHEVDISTANCE_H

#include <vector>
#include "AbstractMeasurer.h"

class ChebyshevDistance : public AbstractMeasurer{
public:
    double getDistance (std::vector<double>&first,std::vector<double> &second) override;

    std::string getName () override;
};
#endif //ADVANCED_PROGRAMIN_PART2_CHEBYSHEVDISTANCE_H
