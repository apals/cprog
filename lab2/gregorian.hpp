#ifndef __LABGREGORIAN__
#define __LABGREGORIAN__
#include "date.hpp"
namespace lab2 {
    class Gregorian : public Date {
        public:
            Gregorian(): Date() {}
            Gregorian(int year, int month, int day): Date(year, month, day){}
            virtual ~Gregorian();

    };
}
#endif
