//
//  Room.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Room.hpp"
#include <map>
#include <string>
#include "StartingRoom.hpp"
namespace lab3 {
    
    Room::Room(std::string name) {
        room_name = name;
    }
    
    std::string Room::get_name() {
        return room_name;
    }
    
    std::map<std::string, Room *> Room::get_adjacent_rooms() {
        std::map<std::string, Room *> rooms;
        return rooms;
    }
    
    std::map<std::string, Room *> GET_ALL_ROOMS() {
        StartingRoom * startingRoom = new StartingRoom("koK");
        StartingRoom * room2 = new StartingRoom("Room 2");
        
        std::map<std::string, Room *> rooms;
        rooms["1"] = startingRoom;
        rooms["2"] = room2;
        
        
        return rooms;
    };
}