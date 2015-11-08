#include "date.hpp"
#include <stdexcept>
#include "kattistime.h"
namespace lab2 {
    Date::Date(){
        // För att få nuvarande tid
        time_t mytime;

        time(&mytime);

       // k_time(&mytime);

        // För att få ut datum lokalt 
        struct tm *t = gmtime(&mytime);
        curr_year  = t->tm_year + 1900;
        curr_month = t->tm_mon + 1;      // månaderna och dagarna
        curr_day   = t->tm_mday;         // indexerade från ETT
    }

    //Copy assignment
    Date& Date::operator=(const Date& other) {
        Date tmp(other);
        std::swap(curr_year, tmp.curr_year);
        std::swap(curr_month, tmp.curr_month);
        std::swap(curr_day, tmp.curr_day);
        std::swap(curr_week_day, tmp.curr_week_day);
        std::swap(curr_days_per_week, tmp.curr_days_per_week);
        int mjd = other.mod_julian_day();
        curr_year = mjd_to_year(mjd);
        curr_month = mjd_to_month(mjd);
        curr_day = mjd_to_day(mjd);
        return *this;
    }

    //Copy constructor
    Date::Date(const Date & obj) {
        curr_year = obj.curr_year;
        curr_month = obj.curr_month;
        curr_day = obj.curr_day;
        curr_week_day = obj.curr_week_day;
        curr_days_per_week = obj.curr_days_per_week;
    }

    Date::~Date(){}

    bool Date::operator==(const Date & b) const {
        return mod_julian_day() == b.mod_julian_day();
    }

    bool Date::operator!=(const Date & b) const {
        return !(*this == b);
    }

    bool Date::operator<=(const Date & b) const{
        return mod_julian_day() <= b.mod_julian_day();
    }
    bool Date::operator>(const Date & b) const{
        return mod_julian_day() > b.mod_julian_day();
    }
    bool Date::operator>=(const Date & b) const{
        return mod_julian_day() >= b.mod_julian_day();
    }

    std::ostream& operator<<(std::ostream &os, Date const &m) { 
        return os << "" << m.year() << "-" << m.month() << "-" << m.day();
    }


    /**
     * Reference for ++, -- operators
     * http://en.cppreference.com/w/cpp/language/operators
     * http://en.cppreference.com/w/cpp/language/operator_incdec
     */

    //predecrement operator
    Date& Date::operator--() {
        (*this) -= 1;
        return *this;
    }

    //postdecrement operator
    Date Date::operator--(int) {
        Date tmp(*this);
        operator--();
        return tmp;
    }

    //preincrement operator
    Date& Date::operator++() {
        (*this) += 1;
        return *this;
    }

    //postincrement operator
    Date Date::operator++(int) {
        Date tmp(*this);
        operator++();
        return tmp;
    }

    /**
     * END ++ AND -- OPERATORS
     */

    //+= operator
    Date& Date::operator+=(const int & n) {
        int mjd = mod_julian_day();
        mjd += n;
        curr_day = mjd_to_day(mjd);
        curr_month = mjd_to_month(mjd);
        curr_year = mjd_to_year(mjd);
        return *this;
    }

    //+= operator
    Date& Date::operator-=(const int & n) {
        (*this) += -n;
        return *this;
    }


    int Date::operator-(const Date &b) const {
        return std::abs(mod_julian_day() - b.mod_julian_day());
    }

    bool Date::operator<(const Date & r) const{
        return mod_julian_day() < r.mod_julian_day();
    }


    Date::Date(int year, int month, int day){
        if(year < 1858 || year > 2558)
            throw std::invalid_argument("Invalid year");
        if(month < 1 || month > 12)
            throw std::invalid_argument("Invalid month");
        curr_year = year;
        curr_month = month;

        if(day < 1 || day > days_this_month())
            throw std::invalid_argument("Invalid day");
        curr_day = day;
    }

    int Date::year() const {
        return curr_year;
    }

    unsigned int Date::month() const {
        return curr_month;
    }

    unsigned int Date::day() const {
        return curr_day;
    }

    unsigned int Date::week_day() const{
        int mjd = mod_julian_day() + 2400001;
        int day = mjd % 7 + 1;
        return day;
    }   

    unsigned int Date::days_per_week() const{
        return curr_days_per_week;
    }

    std::string Date::week_day_name() const{
        int day = week_day();

        switch(day) {
            case 1:
                return "MONDAY";
            case 2:
                return "TUESDAY";
            case 3:
                return "WEDNESDAY";
            case 4: 
                return "THURSDAY";
            case 5:
                return "FRIDAY";
            case 6:
                return "SATURDAY";
            case 7:
                return "SUNDAY";
        }
        throw std::out_of_range("Week day is smaller than 1 or bigger than 7");
    }

    unsigned int Date::days_this_month() const{
        int days_this_month = 30;

        //Count knuckles
        if (curr_month % 2 != 0 && curr_month <= 7) {
            days_this_month = 31;
        } else if (curr_month > 7 && curr_month % 2 == 0){
            days_this_month = 31;
        }

        //If february and leap year
        if (curr_month == 2) {
            if (is_leap_year(curr_year)) 
                days_this_month = 29;
            else 
                days_this_month = 28;
        }
        return days_this_month;
    }
    /**
     * In the Gregorian calendar 3 criteria must be taken into account to identify leap years:
     *
     * 1: The year is evenly divisible by 4;
     * 2: If the year can be evenly divided by 100, it is NOT a leap year, unless;
     * 3: The year is also evenly divisible by 400. Then it is a leap year.
     */
    bool Date::is_leap_year(int year) const{

        //CRITERIA 1
        if(year % 4 != 0) {
            return false;
        }

        //CRITERIA 2 && 3
        if(year % 100 == 0) {
            if(year % 400 != 0) {
                return false;
            }

        }

        return true;
    }

    std::string Date::month_name() const {
        std::string name;

        if(curr_month == 1) 
            name = "JANUARY";
        else if(curr_month == 2) 
            name = "FEBRUARY";
        else if(curr_month == 3) 
            name = "MARCH";
        else if(curr_month == 4) 
            name = "APRIL";
        else if(curr_month == 5) 
            name = "MAY";
        else if(curr_month == 6) 
            name = "JUNE";
        else if(curr_month == 7) 
            name = "JULY";
        else if(curr_month == 8) 
            name = "AUGUST";
        else if(curr_month == 9) 
            name = "SEPTEMBER";
        else if(curr_month == 10) 
            name = "OCTOBER";
        else if(curr_month == 11) 
            name = "NOVEMBER";
        else if(curr_month == 12) 
            name = "DECEMBER";
        return name;
    }

    void Date::add_year(int n) {
        curr_year += n;
        if (curr_day > days_this_month()) {
            curr_day = days_this_month();
        }
    }

    void Date::add_month(int n){
        int curr_month_holder = curr_month + n;
        int years_to_add = 0;
        if(n > 0) {
            for(int i = 0; curr_month_holder > 12; i++) {
                curr_month_holder -= 12;
                years_to_add++;
            }
        }
        else {
            for(int i = 0; curr_month_holder < 1; i++) {
                curr_month_holder += 12;
                years_to_add--;
            }
        }
        curr_month = curr_month_holder;
        curr_year+= years_to_add;

        if (curr_day > days_this_month()) {
            curr_day = days_this_month();
        }

    }

    int Date::mod_julian_day() const {
        int a = floor((14 - curr_month)/12);
        int y = curr_year + 4800 - a;
        int m = curr_month + 12 * a - 3;
        int jdn = curr_day 
            + floor((153 * m + 2)/5)
            + 365 * y
            + floor(y/4)
            - floor(y/100)
            + floor(y/400)
            - 32045;
        return jdn-2400001;
    }


    int Date::mjd_to_date(int mjd, int mode, bool greg) const {
        mjd+=2400001;
        int y = 4716;
        int j = 1401;
        int m = 2;
        int n = 12;
        int r = 4;
        int p = 1461;
        int v = 3;
        int u = 5;
        int s = 153;
        int w = 2;
        int B = 274277;
        int C = -38;
        int f;
        if(greg == true)
        {
            f = mjd 
                + j 
                + (((4*mjd+B)/146097)*3)/4
                + C;
        }
        else
        {
            f = mjd + j;
        }
        int e = r * f + v;
        int g = (e%p)/r;
        int h = u * g + w;
        int D = (h%s)/u + 1;
        int M = (h/s+m)%n + 1;
        int Y = e/p - y + (n + m - M)/n;
        switch(mode){
            case 0:
                return D;
            case 1:
                return M;
            case 2:
                return Y;
            default:
                throw std::invalid_argument("Invalid mode");
        }
    }

    int Date::mjd_to_day(int mjd) const {
        return mjd_to_date(mjd, 0, true);
    }

    int Date::mjd_to_month(int mjd) const {
        return mjd_to_date(mjd, 1, true);
    }

    int Date::mjd_to_year(int mjd) const {
        return mjd_to_date(mjd, 2, true);
    }
}
