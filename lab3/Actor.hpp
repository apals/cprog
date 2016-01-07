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
    class Object;
    
    class Actor {
        
    public:
        Actor(std::string name, Room * location);
        int hp();
        virtual Room * location();
        
        virtual std::string type() = 0;
        std::string name();
        virtual void action() = 0;
        void go(std::string direction);
        void fight(Actor * a);
        void talk_to(Actor * a);
        void pick_up(Object * o);
        void drop(Object * o);
        void use(Object * o);
        virtual void lose_hp(int amt);
        bool is_alive();
        void print_location();
        void print_inventory();
        std::vector<Object *> get_inventory();
    protected:
        int curr_hp = 6;
        Room * curr_location;
        int curr_type;
        std::string curr_name;
        std::vector<Object *> inventory;
    };
    
   
    
}
#endif /* Actor_hpp */
