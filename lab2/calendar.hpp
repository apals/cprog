#ifndef __LABCALENDAR__
#define __LABCALENDAR__
#include <string>
#include <list>
#include <iostream>
namespace lab2 {
    template <typename DateType>
        struct Event {
            public: 
                Event();
                ~Event(){
                    delete date;
                };
                Event(std::string n, int d, int m, int y){
                    event_name = n;
                    date = new DateType(y, m, d);
                };

                std::string event_name;
                DateType * date;
        };
    template <typename DateType>
        class Calendar {
            public:
                Calendar();

                template <typename U>
                    Calendar(const Calendar<U> & other) {
                        std::cout << "thiniges " << std::endl;
                        date = new DateType((*other.date));/*other.date->year(),
                                other.date->month(),
                                other.date->day());*/
                    }
                ~Calendar();
                void set_date(int d, int m, int y);
                bool isEqual(Event<DateType> * e, std::string event_name, int d, int m, int y);
                bool isValid(std::string event_name, int d, int m, int y);

                bool add_event(std::string event_name, int d, int m, int y);
                bool add_event(std::string event_name, int d, int m);
                bool add_event(std::string event_name, int d);

                bool remove_event(std::string event_name, int d, int m, int y);
                bool remove_event(std::string event_name, int d, int m);
                bool remove_event(std::string event_name, int d);

                template <typename Other>
                    friend std::ostream& operator<<(std::ostream &os, Calendar<Other> const & c);
                DateType * date;

            private:
                std::list<Event<DateType> *> event_list;
        };
}

#include "calendar_impl.hpp"
#endif
