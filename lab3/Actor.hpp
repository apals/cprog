//
//  Actor.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>
#include "Room.hpp"
#include "Object.hpp"
namespace lab3 {
    
    //circular dependency fix
    class Room;
    
    class Actor {
        
    public:
        Actor(Room * location) : curr_location(location) {};
        int hp();
        virtual Room * location();
        
        std::string type();
        std::string name();
        void action();
        void go(std::string direction);
        void fight(Actor * a);
        void talk_to(Actor * a);
        void pick_up(Object * o);
        void drop(Object * o);
        
    protected:
        int curr_hp;
        Room * curr_location;
        int curr_type;
    };
    
   
    
}
#endif /* Actor_hpp */
