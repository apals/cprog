#ifndef __LABCALENDAR__
#define __LABCALENDAR__
#include <string>
#include <list>
#include <iostream>
namespace lab2 {
    struct Event {
        std::string event_name;
        int day, month, year;
    };
    template <typename DateType>
        class Calendar {
            public:
                Calendar();
                void set_date(int d, int m, int y);

                bool add_event(std::string event_name, int d, int m, int y);
                bool add_event(int d, int m, int y);
                bool add_event(int d, int m);
                bool add_event(int d);

                bool remove_event(std::string event_name, int d, int m, int y);
                bool remove_event(int d, int m, int y);
                bool remove_event(int d, int m);
                bool remove_event(int d);

                friend std::ostream& operator<<(std::ostream &os, Calendar<DateType> const & c);

            private:
                std::list<Event> event_list;
                DateType * date;
        };
}

#include "calendar_impl.hpp"
#endif
