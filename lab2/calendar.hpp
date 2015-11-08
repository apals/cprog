#ifndef __LABCALENDAR__
#define __LABCALENDAR__
#include <string>
#include <list>
#include <iostream>
namespace lab2 {
    struct Event {
        public: 
            Event();
            Event(std::string n, int d) : event_name(n), day(d) {}
            Event(std::string n, int d, int m) : event_name(n), day(d), month(m) {}
            Event(std::string n, int d, int m, int y) : event_name(n), day(d), month(m), year(y) {}
            std::string event_name;
            int day, month, year;
    };
    template <typename DateType>
        class Calendar {
            public:
                Calendar();
                ~Calendar();
                void set_date(int d, int m, int y);

                bool add_event(std::string event_name, int d, int m, int y);
                bool add_event(std::string event_name, int d, int m);
                bool add_event(std::string event_name, int d);

                bool remove_event(std::string event_name, int d, int m, int y);
                bool remove_event(std::string event_name, int d, int m);
                bool remove_event(std::string event_name, int d);
        
                template <typename Other>
                friend std::ostream& operator<<(std::ostream &os, Calendar<Other> const & c);

            private:
                std::list<Event *> event_list;
                DateType * date;
        };
}

#include "calendar_impl.hpp"
#endif
