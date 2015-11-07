#ifndef __LABGREGORIAN__
#define __LABGREGORIAN__
#include "date.hpp"
namespace lab2 {
    class Gregorian : public Date {
        public:
            Gregorian(): Date() {}
            Gregorian(const Date & other) : Date(other) {}
            Gregorian& operator=(const Date & other);
            Gregorian(int year, int month, int day): Date(year, month, day){}
            virtual ~Gregorian();

    };
}
#endif
