//Rotem Zilberman 213231418
//Ohad Langer

#include <stdexcept>
#include <iostream>
#include "Helper.h"

int Helper::NumElement(std::string &input, char separator) {
    int counter=0;
    for (char i : input) {
        counter += i==separator;
    }
    return counter+1;
}

double *Helper::GetArr(std::string &a, char separator) {
    double *arr = new double [NumElement(a, separator)];
    std::string number;
    int numIndex=0;
    for(char c : a) {
        if(c!=separator){
            number+=c;
        } else{
            arr[numIndex] = StringToDouble(number);
            number = "";
            numIndex++;
        }
    }
    arr[numIndex] = StringToDouble(number);
    return arr;
}

std::vector<double> Helper::StringToVector(std::string &input, char separator) {
    int size = NumElement(input,separator);
    double *arr;
    arr = GetArr(input, separator);
    std::vector<double> vector(arr, arr + size);
    return vector;
}
std::vector<std::string> Helper::InputConvert(std::string &input, char separator) {
    std::vector<std::string> result;
    int last = int(input.rfind(separator));
    if(last == -1){
        throw std::invalid_argument("invalid input");
    }
    try {
        std::string k = input.substr(last + 1, input.length() - last - 1);
        std::string sub = input.substr(0, last);
        last = int(sub.rfind(separator));
        if (last == -1) {
            throw std::invalid_argument("invalid input");
        }
        std::string method = sub.substr(last + 1, sub.length() - last - 1);
        std::string vector = input.substr(0, last);
        result = std::vector<std::string>({vector, method, k});
    }
    catch(std::exception &e){
        throw std::invalid_argument("invalid input");
    }
    return result;
}

double Helper::StringToDouble(std::string &input) {
    size_t length;
    double num;
    try{
        num = std::stod(input,&length);
    }
    catch(std::exception &exception){
        throw std::invalid_argument("invalid number");
    }
    if(length != input.length()){
        throw std::invalid_argument("invalid number");
    }
    return num;
}
