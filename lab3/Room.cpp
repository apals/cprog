//
//  Room.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Room.hpp"
#include <string>
namespace lab3 {
    
    Room::Room(std::string name) {
        room_name = name;
    }
    
    std::string Room::get_name() {
        return room_name;
    }
}