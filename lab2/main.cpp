#include "date.hpp"
#include "gregorian.hpp"
#include "julian.hpp"
#include "calendar.hpp"
#include <iostream>
using namespace lab2;
int main(){
    { 
        // DOM HÄR TESTFALLEN FUNGEAR BrOR

        /*           const Date d (1900, 1, 1);
                     std::cout << d.week_day() << std::endl;
                     Gregorian g (1900, 1, 1);
                     Julian j (1899, 12, 19);
                     std::cout << "SHOULD BE FALSE: " << (j == g) << std::endl;
                     j++; // increment ‘j‘ by one day
                     std::cout << "SHOULD BE TRUE: " <<  (j == g) << std::endl;
                     j++; // increment ‘j‘ by one day
                     std::cout << "SHOULD BE FALSE: " <<  (j == g) << std::endl;
                     */  }
    { 
        // WORKS!!!
        /*                       Gregorian g (1858, 11, 16);
                                 Julian j (g);
                                 std::cout << "SHOULD BE 1858-11-4 " << j << std::endl; // shall print 1858-11-4
                                 std::cout << "should be 1858-11-16 " << g << std::endl; // shall print 1858-11-16

                                 Julian j2(1858, 11, 4);
                                 Gregorian g2(j2);
                                 std::cout << "SHOULD BE 1858-11-4 " << j2 << std::endl; // shall print 1858-11-4
                                 std::cout << "should be 1858-11-16 " << g2 << std::endl; // shall print 1858-11-16
                                 */                        }
    { 
        /** THIS WORKS TOO **/
        /*   Date * p1 = new Julian ();
             Date * p2 = new Gregorian ();
             std::cout << "should be true: " << (*p1 == *p2) << std::endl; // shall be true

        //TODO: impl virtual destructors
        delete p1;
        delete p2;*/
    }

    {
        /*       std::cout << "1 ----------- " << std::endl;
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
                 */
    }

    {
        /*      Julian j(2015, 7, 5);
                std::cout << j.days_this_month() << std::endl;
                */ }

    {
        /*   Julian g(2097, 3, 5);
             std::cout << "GREGGE:  " << g << " : " << g.mod_julian_day() << std::endl;
             Gregorian j;
             std::cout << "JullI:  " << j << " : " << j.mod_julian_day() << std::endl;
             j = g;
             std::cout << "julle2:  " << j << " : " << j.mod_julian_day() <<  std::endl;
             std::cout << "GREGGE:  " << g << " : " << g.mod_julian_day() << std::endl;
             */}

    {
        /*  Gregorian g(1988, 2, 5);
            g.add_year(2);
            g += 2;
            g.add_month(2);
            g -= 2;
            g += -2;
            g.add_year(-2);
            g -= -2;
            g++;
            g.add_month(-2);
            g--;

            std::cout << "GREGGE:  " << g << " : " << g.days_this_month() << std::endl;
            */
    }

    {
        /*Calendar<Julian> cal;
          cal.add_event("fizbar", 12, 8, 2015);
          cal.set_date(1900, 1, 1);
          cal.add_event("birbaz", 12, 10);
          cal.add_event("foobar", 12);
          cal.add_event("fizbar", -1, -1, -1);
          cal.add_event("fizbar", 0, 0, 0);
          cal.remove_event("foobar", 12, 8, 2015);
          std::cout << cal << std::endl;
          std::cout << (*cal.date) << std::endl;

          std::cout << "----------------" << std::endl;

        //std::cout << "check below ----------------" << std::endl;

        Calendar<Gregorian> cal2(cal);
        std::cout << cal2 << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << (*cal2.date) << std::endl;
        */
        /*lab2::Calendar<lab2::Julian> cj;

          cj.set_date  (1900, 1, 1);

          cj.add_event ("birbaz", 12, 10);
          cj.add_event ("foobar", 12);

          std::cout << lab2::Calendar<lab2::Gregorian> (cj);
          */

        /*Calendar<Gregorian> greg;
          std::cout << greg << std::endl;
          greg.set_date(2012, 2, 29);
          greg.add_event("pNGVXBK", 7, 2);
          greg.remove_event("pNGVXBK", 11, -9);
          greg.set_date(1990, 2, 29);
          std::cout << "-------------" << std::endl;
          std::cout << greg << std::endl;
          std::cout << (*greg.date) << std::endl;*/

        /*Calendar<Gregorian> gregge2;
          gregge2.set_date(1990, 2, 29);
          gregge2.add_event("das", 21, 1);
          gregge2.set_date(2001, 1, 1);
          gregge2.remove_event("das", 21, 1);
          gregge2.set_date(1990, 2, 29);


          Calendar<Julian> julle2(gregge2);
          Calendar<Julian> julle3(julle2);

          std::cout << (*julle2.date) << std::endl;
          std::cout << (julle2) << std::endl;
          std::cout << "------------------" << std::endl;
          std::cout << (*julle3.date) << std::endl;
          std::cout << (julle3) << std::endl; */
        Calendar<Gregorian> greg;
        Calendar<Julian> jul;

        if(greg.set_date(1900, 2, 29)) {
            std::cout << "Greg could set 1900 2 29 " << std::endl;
        }
        if(jul.set_date(1900, 2, 29)) {
            std::cout << "Jul could set 1900 2 29 " << std::endl;
        }

        if(jul.date->is_leap_year(1900)) {
            std::cout << "1900 is a leap year " << std::endl;
        }
    }
}
