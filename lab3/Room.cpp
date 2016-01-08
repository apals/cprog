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
    
    Room::Room(std::string name, std::string description) : room_name(name), room_description(description) {
    }
    
    std::string Room::name() {
        return room_name;
    }
    
    void Room::print_directions() {
        std::cout << "Directions: " << std::endl;
        for(auto const &ent1 : neighbors) {
            std::cout << '\t' << ent1.first << ": " << ent1.second->name() << std::endl;
        }
        std::cout << std::endl;
    }
    
    void Room::print_actors_in_room() {
        std::cout << "Actors in room: " << std::endl;
        for(auto const & a : actors_in_room) {
            std::cout << '\t' << a->name() << std::endl;
        }
        std::cout << std::endl;
    }
    
    void Room::print_objects_in_room() {
        std::cout << "Objects in room: " << std::endl;
        for(auto const & o : objects_in_room) {
            std::cout << '\t' << o->name() << std::endl;
        }
        std::cout << std::endl;
    }
    
    Room * Room::neighbor(std::string direction) {
        return neighbors[direction];
    }
    
    std::string Room::description() {
        return " asd " ;
    }
    
    bool Room::enter(Actor * a) {
        actors_in_room.push_back(a);
        return true;
    }
    
    void Room::leave(Actor * a) {
        actors_in_room.erase(std::remove(actors_in_room.begin(), actors_in_room.end(), a), actors_in_room.end());
    }
    
    void Room::enter(Object * a) {
        objects_in_room.push_back(a);
    }
    
    void Room::leave(Object * a) {
        objects_in_room.erase(std::remove(objects_in_room.begin(), objects_in_room.end(), a), objects_in_room.end());
    }
    Room::~Room() {
    }
    
    void Room::print_description() {
        std::cout << room_description << std::endl;
    }
}