#include "Date.hpp"
#include "kattistime.h"

Date::Date(){
    // För att få nuvarande tid
    time_t mytime;
    //k_time(&mytime);

    // För att få ut datum lokalt 
    time(&mytime);
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

std::ostream& operator<<(std::ostream &os, Date const &m) { 
        return os << "" << m.curr_year << "-" << m.curr_month << "-" << m.curr_day;
}


/**
 * Reference for ++, -- operators
 * http://en.cppreference.com/w/cpp/language/operators
 * http://en.cppreference.com/w/cpp/language/operator_incdec
 */

//predecrement operator
Date& Date::operator--() {
    //TODO: logic with days < 0 etc
    curr_day--;
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
    //TODO: logic with days > 30, 31 etc
    curr_day++;
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
    //TODO: impl
    return *this;
}

//+= operator
Date& Date::operator-=(const int & n) {
    //TODO: impl
    return *this;
}

Date Date::operator+(const Date &b) const {
    Date d;
    return d;
}

Date Date::operator-(const Date &b) const {
    Date d;
    return d;
}

bool Date::operator<(const Date & r) {

    return mod_julian_day() < r.mod_julian_day();

    /*if (year() < r.year())
        return true;
    else if(year() > r.year())
        return false;

    if(month() < r.month())
        return true;
    else if(month() > r.month())
        return false;

    if(day() < r.day())
        return true;
    else if(day() > r.day())
        return false;

    //They are equal
    return false;*/

}


Date::Date(int year, int month, int day){
    curr_year = year;
    curr_month = month;
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

unsigned int Date::week_day() {
    return curr_week_day;
}   

unsigned int Date::days_per_week() {
    return curr_days_per_week;
}

std::string Date::week_day_name(){
    switch(curr_week_day) {
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

unsigned int Date::days_this_month() {
    int days_this_month;

    //Count knuckles
    if (curr_month % 2 != 0) {
        days_this_month = 31;
    }

    //If february and leap year
    if (curr_month == 2) {
        if (curr_year % 4 == 0) 
            days_this_month = 29;
        else 
            days_this_month = 28;
    }
    return days_this_month;
}

std::string Date::month_name() {
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

}

void Date::add_month(int n){
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
    return jdn;
}


