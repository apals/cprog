#ifndef __DATE__
#include <iostream>
class Date {
    public:
        int year();
        unsigned int month();
        unsigned int day();
        unsigned int week_day();
        unsigned int days_per_week();
        unsigned int days_this_month();
        std::string week_day_name();
        std::string month_name();
        int add_year(int n);
        int add_month(int n);
        int mod_julian_day();

    private:
        int curr_year;
        unsigned int curr_month;
        unsigned int curr_day;
        unsigned int curr_week_day;
        unsigned int curr_days_per_week;
};
#endif
