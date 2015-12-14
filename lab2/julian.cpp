#include "julian.hpp"
namespace lab2 {

    Julian::Julian(): Gregorian() {
        int mjd = Gregorian::mod_julian_day();
        curr_year = mjd_to_year(mjd);
        curr_month = mjd_to_month(mjd);
        curr_day = mjd_to_day(mjd);
    }

    Julian::Julian(const Date& g){
        curr_year = mjd_to_year(g.mod_julian_day());
        curr_month = mjd_to_month(g.mod_julian_day());
        curr_day = mjd_to_day(g.mod_julian_day());
    }

    Julian& Julian::operator=(const Date& other) {
        Julian tmp(other);
        std::swap(curr_year, tmp.curr_year);
        std::swap(curr_month, tmp.curr_month);
        std::swap(curr_day, tmp.curr_day);
        std::swap(curr_week_day, tmp.curr_week_day);
        std::swap(curr_days_per_week, tmp.curr_days_per_week);
        return *this;
    }


    Julian::~Julian(){}

    int Julian::mod_julian_day() const {
        //std::cout << "Julian mod_julian_day " << std::endl;
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

    bool Julian::is_leap_year(int year) const {
        return year % 4 == 0;
    }

    int Julian::mjd_to_day(int mjd) const {
        return mjd_to_date(mjd, 0, false);
    }

    int Julian::mjd_to_month(int mjd) const {
        return mjd_to_date(mjd, 1, false);
    }

    int Julian::mjd_to_year(int mjd) const {
        return mjd_to_date(mjd, 2, false);
    }
}
