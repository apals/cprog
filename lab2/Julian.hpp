#ifndef __LABJULIAN__
#define __LABJULIAN__
#include "Gregorian.hpp"
class Julian : public Gregorian {
    public:
        Julian(): Gregorian() {}
        Julian(int year, int month, int day): Gregorian(year, month, day) {}
        Julian(const Gregorian & obj);
        bool operator==(const Gregorian & g) const;
        bool asd();

};

#endif
