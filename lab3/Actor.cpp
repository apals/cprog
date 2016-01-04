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
    
    int Actor::hp() {
        return curr_hp;
    }
    
    Room * Actor::location() {
        return curr_location;
    }
    
    
    
    std::string Actor::type() {
        return "";
    }
    std::string Actor::name() {
        return "";
    }
    void Actor::action() {
        
    }
    
    void Actor::go(std::string direction) {
        std::map<std::string, Room * >::iterator it = curr_location->neighbors.find(direction);
        
        
        if(it != curr_location->neighbors.end()){
            curr_location = curr_location->neighbors[direction];
            std::cout << "I am now in " << curr_location->name() << std::endl;
        } else {
            std::cout << "You can't walk that way" << std::endl;
        }
    }
    
    void Actor::fight(Actor * a) {
        
    }
    void Actor::talk_to(Actor * a) {
        
    }
    void Actor::pick_up(Object * o) {
        
    }
    void Actor::drop(Object * o) {
        
    }
}