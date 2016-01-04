//
//  Actor.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Actor.hpp"
#include <string>
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