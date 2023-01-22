//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART4_DEFAULTIO_H
#define ADVANCED_PROGRAMIN_PART4_DEFAULTIO_H

#include <string>

class DefaultIO {
public:
    /*
     * read data from the io api
     */
    virtual std::string read() = 0;
    /*
     * write data from the io api
     */
    virtual void write(std::string) = 0;
};


#endif //ADVANCED_PROGRAMIN_PART4_DEFAULTIO_H
