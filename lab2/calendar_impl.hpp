//This is the impl
#include <string>
#include <iostream>
namespace lab2 {

    template <typename DateType>
        Calendar<DateType>::Calendar() {
            date = new DateType();
        }

    template <typename DateType>
        void Calendar<DateType>::set_date(int y, int m, int d) {
            delete date;
            date = new DateType(y, m, d);
        }

    template <typename DateType>
        bool Calendar<DateType>::add_event(std::string event_name, int d, int m, int y) {
            Event * e = new Event(event_name, d, m, y);
            event_list.push_back(e);
            return true;
        }
    template <typename DateType>
        bool Calendar<DateType>::add_event(int d, int m, int y) {
            Event * e = new Event(d, m, y);
            event_list.push_back(e);
            return true;
        }
    template <typename DateType>
        bool Calendar<DateType>::add_event(int d, int m) {
            Event * e = new Event(d, m);
            event_list.push_back(e);
            return true;
        }
    template <typename DateType>
        bool Calendar<DateType>::add_event(int d) {
            Event * e = new Event(d);
            event_list.push_back(e);
            return true;
        }

    template <typename DateType>
    bool Calendar<DateType>::remove_event(std::string event_name, int d, int m, int y) {
        for(auto a : event_list) {
            if(a.event_name == event_name && a.d == d && a.m == m && a.y == y) {
                event_list.remove(a);
                delete a;
            }
            return false;
        }
    }
    template <typename DateType>
        bool Calendar<DateType>::remove_event(int d, int m, int y) {
            return false;
        }
    template <typename DateType>
        bool Calendar<DateType>::remove_event(int d, int m) {
            return false;
        }
    template <typename DateType>
        bool Calendar<DateType>::remove_event(int d) {
            return false;
        }

    template <typename DateType>
        std::ostream& operator<<(std::ostream &os, const Calendar<DateType> & c) {
            return os << " printing calendar " << std::endl;
        }

}
