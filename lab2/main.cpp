#include "Date.hpp"
#include "Gregorian.hpp"
#include "Julian.hpp"
#include <iostream>

int main(){
    { 
        Gregorian g (1858, 11, 16);
        std::cout << g.mod_julian_day() << std::endl;
        //j++; // increment ‘j‘ by one day
        //j == g; // shall yield true
    }
    { 
        /*
        Gregorian g (1858, 11, 16);
        Julian j (g);
        std::cout << j; // shall print 1858-11-4
        std::cout << g; // shall print 1858-11-16
        */
    }
    { 
        /*
        Date * p1 = new Julian ();
        Date * p2 = new Gregorian ();
        *p1 == *p2; // shall be true
        delete p1;
        delete p2;
        */
    }

}
