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
#include "Actor.hpp"

namespace lab3 {
    
    //circular dependencies, this fixes it
    class Actor;
    
    class Room {
    public:
        Room(std::string name);
        std::string name();        
        virtual void directions();
        virtual Room * neighbor(std::string direction);

        
        std::string description();
        void enter(Actor * a);
        void leave(Actor * a);
        std::map<std::string, Room *> neighbors;
    private:
        std::string room_name;
        std::string room_description;
    };
    
    
    
    
   // std::map<std::string, Room * > GET_ALL_ROOMS();
    
}

#endif /* Room_hpp */
