//
//  Object.hpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include <string>
#include "Room.hpp"
#include "Actor.hpp"
namespace lab3 {
    
    class Room;
    class Actor;
 
    class Object {
    public:
        Object(std::string name);
        virtual ~Object();
        int weight();
        int volume();
        int price();
        std::string name();
        Room * location();
        void set_location(Room * location);
        virtual bool use(Actor * a);
    private:
        std::string curr_name;
        Room * curr_location;
        
    };
}
#endif /* Object_hpp */
