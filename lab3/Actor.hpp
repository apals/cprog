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
#include "Container.hpp"
namespace lab3 {
    
    //circular dependency fix
    class Room;
    class Object;
    class Container;
    
    class Actor {
        
    public:
        Actor(std::string name, Room * location);
        virtual ~Actor();
        int hp();
        virtual Room * location();
        
        virtual std::string type() const;
        std::string name() const;
        virtual void action() = 0;
        void go(std::string direction);
        void fight(Actor * a);
        void talk_to(Actor * a);
        void pick_up(Object * o);
        void drop(Object * o);
        void use(Object * o);
        virtual void lose_hp(int amt);
        bool is_alive() const;
        void print_location() const;
        void print_inventory() const;
        std::vector<Object *> get_inventory() const;
        void set_hp(int hp);
    protected:
        int curr_hp = 6;
        Room * curr_location;
        int curr_type;
        std::string curr_name;
        Container * inventory;
    };
    
   
    
}
#endif /* Actor_hpp */
