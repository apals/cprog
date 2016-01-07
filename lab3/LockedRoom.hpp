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
        LockedRoom(std::string name, std::vector<Object *> items) : Room(name), needed_items(items) {}
        virtual bool enter(Actor * a);
    private:
        std::vector<Object *> needed_items;
    };
}

#endif /* LockedRoom_hpp */
