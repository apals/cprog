#include "Date.cpp"
#include "Gregorian.hpp"
#include <iostream>

int main(){
    Gregorian g;
    std::cout << g.year() << std::endl;

    Date d;
    std::cout << d.year() << std::endl;
    std::cout << d.month() << std::endl;
    std::cout << d.day() << std::endl;
}
