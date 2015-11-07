#ifndef __LABCALENDAR__
#define __LABCALENDAR__
namespace lab2 {
    template <typename DateTime>
        class Calendar {
            public:
                void set_date(int d, int m, int y);

                bool add_event(std::string event_name, int d, int m, int y);
                bool add_event(int d, int m, int y);
                bool add_event(int d, int m);
                bool add_event(int d);

                bool remove_event(std::string event_name, int d, int m, int y);
                bool remove_event(int d, int m, int y);
                bool remove_event(int d, int m);
                bool remove_event(int d);
        }
}
#include "calendar_impl.hpp"
#endif
