#ifndef __LABCALENDAR__
#define __LABCALENDAR__
#include <string>
#include <list>
#include <iostream>
namespace lab2 {
    template <typename DateType>
        struct Event {
            public: 
                ~Event(){
                    //std::cerr << "destructor event" << std::endl;
                    delete date;
                    //std::cerr << "done with destructor event" << std::endl;
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

                Calendar(const Calendar<DateType> & other){
                    //std::cout << "copy assign of same type" << std::endl;
                    //std::cout << *(other.date) << std::endl;

                    date = new DateType((*other.date).year(), (*other.date).month(), (*other.date).day());
                    //std::cout << *(date) << std::endl; 

                    for(auto a : other.event_list){

                        DateType tmp(*(a->date));
                        event_list.push_back(new Event<DateType>(a -> event_name, (a->date)->day(), (a->date) ->month(), (a -> date) -> year()));
                    }
                }

                template <typename U>
                    Calendar(const Calendar<U> & other) {
                        date = new DateType((*other.date));
                        for(auto a : other.event_list){
                            //event_list.push_back(new Event<DateType>(a -> event_name, a -> date -> day(), a -> date -> month(), a -> date -> year()));

                            DateType tmp(*(a->date));
                            event_list.push_back(new Event<DateType>(a -> event_name, tmp.day(), tmp.month(), tmp.year()));
                        }
                    }
                ~Calendar();
                bool set_date(int d, int m, int y);
                bool isEqual(Event<DateType> * e, std::string event_name, int d, int m, int y);
                bool isValid(std::string event_name, int d, int m, int y);

                bool add_event(std::string event_name, int d, int m, int y);
                bool add_event(std::string event_name, int d, int m);
                bool add_event(std::string event_name, int d);
                bool add_event(std::string event_name);

                bool remove_event(std::string event_name, int d, int m, int y);
                bool remove_event(std::string event_name, int d, int m);
                bool remove_event(std::string event_name, int d);
                bool remove_event(std::string event_name);

                template <typename Other>
                    friend std::ostream& operator<<(std::ostream &os, Calendar<Other> const & c);
                DateType * date;
                std::list<Event<DateType> *> event_list;
        };
}

#include "calendar_impl.hpp"
#endif
