//
//  LockedRoom.hpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef LockedRoom_hpp
#define LockedRoom_hpp

#include <stdio.h>
#include "Room.hpp"
#include <vector>

namespace lab3 {
    class LockedRoom : public Room {
    public:
        LockedRoom(std::string name, std::string description, std::vector<Object *> items) : Room(name, description), needed_items(items){}
        virtual bool enter(Actor * a);
        void set_npc_entrance(std::string type){
            unlimited_entrance.push_back(type);
        }
    private:
        std::vector<Object *> needed_items;
        std::vector<std::string> unlimited_entrance;
    };
}

#endif /* LockedRoom_hpp */
