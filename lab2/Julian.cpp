#include "Julian.hpp"

Julian::Julian(): Gregorian() {
    int mjd = Gregorian::mod_julian_day();
    curr_year = mjd_to_julian_year(mjd);
    curr_month = mjd_to_julian_month(mjd);
    curr_day = mjd_to_julian_day(mjd);
}

Julian::Julian(const Gregorian& g){
    curr_year = g.mjd_to_julian_year(g.mod_julian_day());
    curr_month = g.mjd_to_julian_month(g.mod_julian_day());
    curr_day = g.mjd_to_julian_day(g.mod_julian_day());
}

int Julian::mod_julian_day() const {
    int a = floor((14 - month())/12);
    int y = year() + 4800 - a;
    int m = month() + 12 * a - 3;
    int jdn = day()
        + floor((153 * m + 2)/5)
        + 365 * y
        + floor(y/4)
        - 32083;
    return jdn-2400001;
}
bool Julian::asd(){
    return true;
}
