#include "Date.hpp"
#include "Gregorian.hpp"
#include "Julian.hpp"
#include <iostream>

int main(){
    { 
        // DOM HÄR TESTFALLEN FUNGEAR BrOR
        /*
        Gregorian g (1900, 1, 1);
        Julian j (1899, 12, 19);
        std::cout << (j == g) << std::endl;
        j++; // increment ‘j‘ by one day
        std::cout << (j == g) << std::endl;
        std::cout << j.mjd_to_julian_year(j.mod_julian_day()) << std::endl;
        std::cout << j.mjd_to_julian_month(j.mod_julian_day()) << std::endl;
        std::cout << j.mjd_to_julian_day(j.mod_julian_day()) << std::endl;
        std::cout << j.mjd_to_greg_year(j.mod_julian_day()) << std::endl;
        std::cout << j.mjd_to_greg_month(j.mod_julian_day()) << std::endl;
        std::cout << j.mjd_to_greg_day(j.mod_julian_day()) << std::endl;
        j++; // increment ‘j‘ by one day
        j == g; // shall yield true */
    }
    { 
        // WORKS!!!
        /*
           Gregorian g (1858, 11, 16);
           Julian j (g);
           std::cout << j << std::endl; // shall print 1858-11-4
           std::cout << g << std::endl; // shall print 1858-11-16
           */
    }
    { 
        Date * p1 = new Julian ();
        Date * p2 = new Gregorian ();
        std::cout << (*p1).mod_julian_day() << std::endl;
        std::cout << (*p2).mod_julian_day() << std::endl;
        std::cout << (*p1) << std::endl;
        std::cout << (*p2) << std::endl;
        std::cout << (*p1 == *p2) << std::endl; // shall be true
        delete p1;
        delete p2;
    }

}
