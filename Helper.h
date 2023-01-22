//Rotem Zilberman 213231418
//Ohad Langer

#ifndef ADVANCED_PROGRAMIN_PART3_HELPER_H
#define ADVANCED_PROGRAMIN_PART3_HELPER_H


#include <string>
#include <vector>
/**
 * this is class of the helper function.
 */
class Helper {
public:
    /**
     * get input and convert it to std::vector<std::string> for k vector and distance
     * @param input is the input
     * @param separator is the separator
     * @return converted string
     */
    static std::vector<std::string> InputConvert(std::string &input, char separator);
    /**
     * get vector as string and return double vector that represented it
     * @param input is the vector as string
     * @param separator is the separator
     * @return std::vector<double> of the vector
     */
    static std::vector<double> StringToVector(std::string &input, char separator);
    /**
     * return the number of the element in input if there is separator between them
     * @param input is the input
     * @param separator is the separator
     * @return return the number of the element in input if there is separator between them
     */
    static int NumElement(std::string &input, char separator);
    /**
     * get number as string and return double number that represented it
     * @param input is the number as string
     * @return double number that represented the string
     */
    static double StringToDouble(std::string &input);
    /**
     * get array of double as string and return double array that represented it
     * @param a is the array as string
     * @param separator is the separator
     * @return array that represented the string
     */
    static double * GetArr (std::string &a, char separator);
};


#endif //ADVANCED_PROGRAMIN_PART3_HELPER_H