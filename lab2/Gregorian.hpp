#ifndef __LABGREGORIAN__
#define __LABGREGORIAN__
#include "Date.hpp"
class Gregorian : public Date {
    public:
        Gregorian(): Date() {}
        Gregorian(int year, int month, int day): Date(year, month, day){}

};

#endif
