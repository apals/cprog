#ifndef __LABDATE__
#define __LABDATE__
#include <iostream>
class Date {
    public:
        Date();
        Date(int year, int month, int day);
        virtual int year();
        virtual unsigned int month();
        virtual unsigned int day();
        virtual unsigned int week_day();
        virtual unsigned int days_per_week();
        virtual unsigned int days_this_month();
        virtual std::string week_day_name() = 0;
        virtual std::string month_name();
        virtual void add_year(int n);
        virtual void add_month(int n);
        int mod_julian_day();

    private:
        int curr_year;
        unsigned int curr_month;
        unsigned int curr_day;
        unsigned int curr_week_day;
        unsigned int curr_days_per_week;
};
#endif
