#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include <iostream>
using namespace lab2;
int main(){
    { 
        // DOM HÄR TESTFALLEN FUNGEAR BrOR
        
           const Date d (1900, 1, 1);
           std::cout << d.week_day() << std::endl;
           Gregorian g (1900, 1, 1);
           Julian j (1899, 12, 19);
           std::cout << "SHOULD BE FALSE: " << (j == g) << std::endl;
           j++; // increment ‘j‘ by one day
           std::cout << "SHOULD BE TRUE: " <<  (j == g) << std::endl;
           j++; // increment ‘j‘ by one day
           std::cout << "SHOULD BE FALSE: " <<  (j == g) << std::endl;
    }
    { 
        // WORKS!!!
           Gregorian g (1858, 11, 16);
           Julian j (g);
           std::cout << "SHOULD BE 1858-11-4 " << j << std::endl; // shall print 1858-11-4
           std::cout << "should be 1858-11-16 " << g << std::endl; // shall print 1858-11-16
    }
    { 
        /** THIS WORKS TOO **/
         Date * p1 = new Julian ();
           Date * p2 = new Gregorian ();
           std::cout << "should be true: " << (*p1 == *p2) << std::endl; // shall be true

        //TODO: impl virtual destructors
        delete p1;
        delete p2;
    }

    {
        std::cout << "1 ----------- " << std::endl;
        Gregorian g1(2004, 1, 30);
        std::cout << g1 << std::endl;
        g1.add_month(1);
        std::cout << g1 << std::endl;


        std::cout << "2 ----------- " << std::endl;
        Gregorian g2(2003, 1, 30);
        std::cout << g2 << std::endl;
        g2.add_month(1);
        std::cout << g2 << std::endl;


        std::cout << "3 ----------- " << std::endl;
        Gregorian g3(2000, 1, 20);
        std::cout << g3 << std::endl;
        g3.add_year(5);
        std::cout << g3 << std::endl;


        std::cout << "4 ----------- " << std::endl;
        Gregorian g4(2004, 2, 29);
        std::cout << g4 << std::endl;
        g4.add_year(1);
        std::cout << g4 << std::endl;


        std::cout << "5 ----------- " << std::endl;
        Gregorian g5(2004, 2, 29);
        std::cout << g5 << std::endl;
        g5.add_year(4);
        std::cout << g5 << std::endl;

    }

    {
        Julian g(2140, 8, 9);
        g.add_year(18);
        //std::cout << g << " : " << g.mod_julian_day() << std::endl;
        g += 18;
        //std::cout << g << " : " << g.mod_julian_day() << std::endl;
        g.add_month(18);
        //std::cout << g << " : " << g.mod_julian_day() << std::endl;
        std::cout << " ----- " << std::endl;
        g -= 18;
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        g += -18;
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        g.add_year(-18);
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        g -= -18;
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        ++g;
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        std::cout << "about to get fukc ed up " << std::endl;
        g.add_month(-18);
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        g--;
        std::cout << g << " : " << g.mod_julian_day() << std::endl;
        std::cout << g.days_per_week() << std::endl;
        std::cout << g.week_day() << std::endl;
        std::cout << g.week_day_name() << std::endl;

    }

}
