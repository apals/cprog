#include "Date.hpp"

Date::Date(){
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

