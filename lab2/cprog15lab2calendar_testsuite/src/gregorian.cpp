#include "gregorian.h"
namespace lab2 {
    Gregorian::~Gregorian(){}
    Gregorian& Gregorian::operator=(const Date & other){
        Date::operator=(other);
        return *this;
    }
}
