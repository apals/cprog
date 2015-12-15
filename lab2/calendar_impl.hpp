//This is the impl
#include <string>
#include <iostream>
namespace lab2 {

    /*template <typename , typename DateType>
      Calendar<DateType>::Calendar(Calendar<T> other) {
      date = new DateType(other.date);
      }
      */
    template <typename DateType>
        Calendar<DateType>::Calendar() {
            date = new DateType();
        }

    template <typename DataType>
        Calendar<DataType>::~Calendar() {
            for(auto a : event_list) {
                delete a;
            }
            delete date;
        }

    template <typename DateType>
        bool Calendar<DateType>::set_date(int y, int m, int d) {
            try {
                //std::cout << "Trying to set date to " << y << "-" << m << "-" << d << std::endl;
                DateType datetest(y, m, d);
            } catch(const std::exception& e) {
                //std::cout << "setting date failed" << std::endl;
                return false; 
            }
                //std::cout << "setting date succeeded" << std::endl;
            delete date;
            date = new DateType(y, m, d);
            return true;

        }

    template <typename DateType>
        bool Calendar<DateType>::isEqual(Event<DateType> * e, std::string event_name, int d, int m, int y){
            if(e -> event_name == event_name && e -> date -> day() == d && e -> date -> month() == m && e -> date -> year() == y)
                return true;
            return false;
        }
    template <typename DataType>
        bool Calendar<DataType>::isValid(std::string event_name, int d, int m, int y){
            for(auto a : event_list){
                if(isEqual(a, event_name, d, m, y))
                    return false;
            }
            try {
                Event<DataType> e(event_name, d, m, y);
            } catch(const std::exception& e) { return false; }
            return true;
        }
    template <typename DateType>
        bool Calendar<DateType>::add_event(std::string event_name, int d, int m, int y) {
            if(!isValid(event_name, d, m, y))
                return false;
            //std::cout << "Adding event: " << d << " - " << m << " - " << y << std::endl;
            Event<DateType> * e = new Event<DateType>(event_name, d, m, y);
            //std::cout << "Added event : " << *(e->date) << std::endl;
            event_list.push_back(e);
            return true;
        }
    template <typename DateType>
        bool Calendar<DateType>::add_event(std::string event_name, int d, int m) {
            if(!isValid(event_name, d, m, date -> year()))
                return false;
            Event<DateType> * e = new Event<DateType>(event_name, d, m, date -> year());
            event_list.push_back(e);
            return true;
        }
    template <typename DateType>
        bool Calendar<DateType>::add_event(std::string event_name, int d) {
            if(!isValid(event_name, d, date -> month(), date -> year()))
                return false;
            Event<DateType> * e = new Event<DateType>(event_name, d, date -> month(), date -> year());
            event_list.push_back(e);
            return true;
        }

    template <typename DateType>
        bool Calendar<DateType>::add_event(std::string event_name) {
            if(!isValid(event_name, date -> day(), date -> month(), date -> year()))
                return false;
            Event<DateType> * e = new Event<DateType>(event_name, date -> day(), date -> month(), date -> year());
            event_list.push_back(e);
            return true;
        }

    template <typename DateType>
        bool Calendar<DateType>::remove_event(std::string event_name, int d, int m, int y) {
            for(auto a : event_list) {
                if(isEqual(a, event_name, d, m, y))
                {
                    event_list.remove(a);
                    delete a;
                    return true;
                }
            }
            return false;
        }

    template <typename DateType>
        bool Calendar<DateType>::remove_event(std::string event_name, int d, int m) {
            for(auto a : event_list) {
                if(isEqual(a, event_name, d, m, date -> year()))
                {
                    event_list.remove(a);
                    delete a;
                    return true;
                }
            }
            return false;
        }
    template <typename DateType>
        bool Calendar<DateType>::remove_event(std::string event_name, int d) {
            for(auto a : event_list) {
                if(isEqual(a, event_name, d, date -> month(), date -> year()))
                {
                    event_list.remove(a);
                    delete a;
                    return true;
                }
            }
            return false;
        }

    template <typename DateType>
        bool Calendar<DateType>::remove_event(std::string event_name) {
            for(auto a : event_list) {
                if(isEqual(a, event_name, date -> day(), date -> month(), date -> year()))
                {
                    event_list.remove(a);
                    delete a;
                    return true;
                }
            }
            return false;
        }

    template <typename DateType>
        std::ostream& operator<<(std::ostream &os, const Calendar<DateType> & c) {
            os << "BEGIN:VCALENDAR" << std::endl;
            os << "VERSION:2.0" << std::endl;
            os << "PRODID:-//hacksw/handcal//NONSGML v1.0//EN" << std::endl;

            for(auto a : c.event_list) {

                if((*(a->date)).year() < c.date->year()
                              || ((*(a->date)).year() == c.date->year() && (*(a->date)).month() < c.date->month())
                              || ((*(a->date)).year() == c.date->year() && (*(a->date)).month() == c.date->month() && (*(a->date)).day() < c.date->day()))
                              continue;


                os << "BEGIN:VEVENT" << std::endl;
                os << "SUMMARY:" + a->event_name << std::endl;



                int month = (*a->date).month();
                int day = (*a->date).day();
                os << "DTSTART:" << (*a->date).year();
                if(month < 10)
                    os << "0";
                os << month;
                if(day < 10)
                    os << "0";
                os << day;
                os << "T000000" << std::endl;
                os << "END:VEVENT" << std::endl;
            }
            return os << "END:VCALENDAR";

        }

}
