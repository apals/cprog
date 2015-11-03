#include "Date.hpp"
#include "Gregorian.hpp"
#include <iostream>

int main(){
    Date d;
    
    std::cout << d.year() << std::endl;
    std::cout << d.month() << std::endl;
    std::cout << d.day() << std::endl;
}
