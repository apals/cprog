#ifndef __LABCALENDAR__
#define __LABCALENDAR__
#include <string>
#include <list>
namespace lab2 {
    struct Event {
        public: 
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

            private:
                std::list<Event> event_list;
                DateType * date;
        };
}

#include "calendar_impl.hpp"
#endif
