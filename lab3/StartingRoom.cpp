//
//  StartingRoom.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "StartingRoom.hpp"
#include <string>

namespace lab3 {
    
    StartingRoom::StartingRoom(std::string name) : Room(name) {
        
    }
    
    std::map<std::string, Room> StartingRoom::get_adjacent_rooms() {
        std::map<std::string, Room> rooms;
        return rooms;
    }
    
}