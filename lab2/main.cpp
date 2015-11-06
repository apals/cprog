#include "Date.cpp"
#include "Gregorian.hpp"
#include <iostream>

int main(){
    Date d;
    std::cout << d.year() << std::endl;
    std::cout << d.month() << std::endl;
    std::cout << d.day() << std::endl;
    std::cout << d << std::endl;


    --d;
    std::cout << d.day()  << std::endl;
    d--;
    std::cout << d.day()  << std::endl;
    ++d;
    std::cout << d.day()  << std::endl;
    d++;
    std::cout << d.day()  << std::endl;
    Gregorian g;
    std::cout << g << std::endl;

    { 
        Gregorian g (1900, 1, 1);
        Julian j (1899, 12, 19);
        j == g; // shall yield false
        j++; // increment ‘j‘ by one day
        j == g; // shall yield true
    }
    { 
        Gregorian g (1858, 11, 16);
        Julian j (g);
        std::cout << j; // shall print 1858-11-4
        std::cout << g; // shall print 1858-11-16
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
