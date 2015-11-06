#include "Julian.hpp"

int Julian::mod_julian_day() {
    int a = floor((14 - month())/12);
    int y = year() + 4800 - a;
    int m = month() + 12 * a - 3;
    int jdn = day()
        + floor((153 * m + 2)/5)
        + 365 * y
        + floor(y/4)
        - 32083;
    return jdn;
}

bool Julian::operator==(const Gregorian & g) const {
    return true;
}
