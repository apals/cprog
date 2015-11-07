//This is the impl
#include <string>
namespace lab2 {

    template <typename DateType>
    Calendar<DateType>::Calendar() {
        date = new DateType();
    }

    template <typename DateType>
    void Calendar<DateType>::set_date(int d, int m, int y) {
        delete date;
        date = new DateType(y, m, d);
    }

    template <typename DateType>
    bool Calendar<DateType>::add_event(std::string event_name, int d, int m, int y) {
        Event * e = new Event();
        event_list.push_back(e);
        return true;
    }
    template <typename DateType>
    bool Calendar<DateType>::add_event(int d, int m, int y) {
        Event * e = new Event();
        event_list.push_back(e);
        return true;
    }
    template <typename DateType>
    bool Calendar<DateType>::add_event(int d, int m) {
        Event * e = new Event();
        event_list.push_back(e);
        return true;
    }
    template <typename DateType>
    bool Calendar<DateType>::add_event(int d) {
        Event * e = new Event();
        event_list.push_back(e);
        return true;
    }

    template <typename DateType>
    bool Calendar<DateType>::remove_event(std::string event_name, int d, int m, int y) {
        return false;
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

}
