//Rotem Zilberman 213231418
//Ohad Langer

#include "StandardIO.h"

std::string StandardIO::read() {
    std::string input;
    std::cin >> input;
    return input;
}

void StandardIO::write(std::string s) {
    std::cout << s;
}