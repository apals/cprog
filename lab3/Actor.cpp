//
//  Actor.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Actor.hpp"
namespace lab3 {
    
    int Actor::hp() {
        return curr_hp;
    }
    
    Room * Actor::location() {
        return curr_location;
    }
}