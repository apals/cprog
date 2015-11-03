#include "Date.hpp"
#include <string>


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

std::string Date::week_day_name() {
    return "-1";
}

std::string Date::month_name() {
    return "-1";
}

void Date::add_year() {

}

int Date::mod_julian_day() {
    return 0;    
}
