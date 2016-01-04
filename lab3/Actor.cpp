//
//  Actor.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Actor.hpp"
#include <string>
#include <iostream>
namespace lab3 {
    
    Actor::Actor(std::string name, Room * location) : curr_name(name), curr_location(location) {
        curr_location->enter(this);
    };
    
    int Actor::hp() {
        return curr_hp;
    }
    
    Room * Actor::location() {
        return curr_location;
    }
    
    std::string Actor::name() {
        return curr_name;
    }
    
    void Actor::action() {
        
    }
    
    void Actor::go(std::string direction) {
        std::map<std::string, Room * >::iterator it = curr_location->neighbors.find(direction);
        
        if(it != curr_location->neighbors.end()){
            curr_location->leave(this);
            curr_location = curr_location->neighbors[direction];
            curr_location->enter(this);
        } else {
            std::cout << "what r u doing u stupid thats just miffo" << std::endl;
        }
        std::cout << std::endl;
    }
    
    
    void Actor::fight(Actor * a) {
        std::cout << name() << " is trying to fight " << a->name() << std::endl;
        a->lose_hp(5);
        std::cout << std::endl;
    }
    
    void Actor::talk_to(Actor * a) {
        
    }
    void Actor::pick_up(Object * o) {
        curr_location->leave(o);
        inventory.push_back(o);
    }
    void Actor::drop(Object * o) {
        curr_location->enter(o);
        inventory.erase(std::remove(inventory.begin(), inventory.end(), o), inventory.end());
    }
    
    void Actor::lose_hp(int amt) {
        curr_hp -= amt;
        std::cout << "Ouch, " << name() << " just got hit! Remaining HP: " << curr_hp << std::endl;
        
        if (curr_hp <= 0) {
            std::cout << name() << " just died... " << std::endl;
        }
    }
    
    bool Actor::is_alive() {
        return curr_hp > 0;
    }
    
    void Actor::print_location() {
        std::cout << name() << " is in " << curr_location->name() << std::endl;
        std::cout << std::endl;
    }
    
    void Actor::print_inventory() {
        std::cout << "Inventory: " << std::endl;
        for(const auto & i : inventory) {
            std::cout << '\t' << i->name() << std::endl;
        }
        std::cout << std::endl;
    }
}