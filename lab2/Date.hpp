#ifndef __LABDATE__
#define __LABDATE__
#include <iostream>
class Date {
    public:
        Date();
        Date(const Date & obj);
        Date(int year, int month, int day);
        Date& operator=(const Date& other);

        Date& operator+=(const int & n);
        Date& operator-=(const int & n);

        Date operator+(const Date & b) const;
        Date operator-(const Date & b) const;

        bool operator<(const Date & l, const Date & r);
       
        std::ostream &operator<<(std::ostream &os, Date const &m);

        //Pre increment
        Date& operator++();
        //Post increment
        Date operator++(int);
        //Pre decrement
        Date& operator--();
        //Post decrement
        Date operator--(int);
        int year() const;
        unsigned int month() const;
        unsigned int day() const;
        virtual unsigned int week_day();
        unsigned int days_per_week();
        virtual unsigned int days_this_month();
        std::string week_day_name();
        std::string month_name();
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
