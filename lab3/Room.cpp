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
#include <iostream>
namespace lab3 {
    
    Room::Room(std::string name) : room_name(name) {
    }
    
    std::string Room::name() {
        return room_name;
    }
    
    void Room::directions() {
        std::cout << "Directions: " << std::endl;
        for(auto const &ent1 : neighbors) {
            std::cout << ent1.first << ": " << ent1.second->name() << std::endl;
        }
    }
    
    Room * Room::neighbor(std::string direction) {
        return neighbors[direction];
    }
    
    std::string Room::description() {
        return " asd " ;
    }
    
    void enter(Actor * a) {
        
    }
    
    void leave(Actor * a) {
        
    }
}