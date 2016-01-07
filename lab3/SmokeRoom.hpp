//
//  SmokeRoom.hpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef SmokeRoom_hpp
#define SmokeRoom_hpp

#include <stdio.h>
#include "Room.hpp"

namespace lab3 {
    class SmokeRoom : public Room {
    public:
        SmokeRoom(std::string name) : Room(name) {}
        virtual bool enter(Actor * a);
    };
}
#endif /* SmokeRoom_hpp */
