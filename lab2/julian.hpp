#ifndef __LABJULIAN__
#define __LABJULIAN__
#include "gregorian.hpp"
namespace lab2 {
    class Julian : public Gregorian {
        public:
            Julian();
            Julian(int year, int month, int day); 
            Julian(const Date & obj);
            Julian& operator=(const Date& other);
            virtual ~Julian();
            virtual int mod_julian_day() const override;
        protected:
            virtual bool is_leap_year(int year) const override;
            virtual int mjd_to_day(int mjd) const override;
            virtual int mjd_to_month(int mjd) const override;
            virtual int mjd_to_year(int mjd) const override;
    };
}
#endif
