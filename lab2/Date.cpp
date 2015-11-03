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

Date::Date(int year, int month, int day){
    curr_year = year;
    curr_month = month;
    curr_day = day;
}

int Date::year() {
    return curr_year;
}

unsigned int Date::month() {
    return curr_month;
}

unsigned int Date::day() {
    return curr_day;
}

unsigned int Date::week_day() {
    return curr_week_day;
}   

unsigned int Date::days_per_week() {
    return curr_days_per_week;
}

std::string Date::week_day_name(){
    return "1";
}

unsigned int Date::days_this_month() {
    //TODO: impl
    return -1;
}

std::string Date::month_name() {
    return "-1";
}

void Date::add_year(int n) {

}

void Date::add_month(int n){
}

int Date::mod_julian_day() {
    return 0;    
}

