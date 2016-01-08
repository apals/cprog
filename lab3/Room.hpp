//
//  Room.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include "Actor.hpp"
#include "Object.hpp"

namespace lab3 {
    
    //circular dependencies, this fixes it
    class Actor;
    class Object;
    
    class Room {
    public:
        Room(std::string name, std::string description);
        virtual ~Room();
        std::string name();        
        virtual void print_directions();
        virtual void print_description();
        virtual void print_actors_in_room();
        virtual void print_objects_in_room();
        virtual Room * neighbor(std::string direction);

        
        std::string description();
        virtual bool enter(Actor * a);
        void leave(Actor * a);
        void enter(Object * o);
        void leave(Object * o);
        std::map<std::string, Room *> neighbors;
        std::vector<Actor *> actors_in_room;
        std::vector<Object *> objects_in_room;
        
    private:
        std::string room_name;
        std::string room_description;
    };
    
    
}

#endif /* Room_hpp */
