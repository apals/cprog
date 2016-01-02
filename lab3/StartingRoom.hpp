//
//  StartingRoom.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef StartingRoom_hpp
#define StartingRoom_hpp

#include <stdio.h>
#include "Room.hpp"
namespace lab3 {
    class StartingRoom : Room {
    public:
        StartingRoom(std::string name);
        virtual std::map<std::string, Room> get_adjacent_rooms();
    };
}

#endif /* StartingRoom_hpp */
