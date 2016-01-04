//
//  Troll.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include <iostream>
#include "Troll.hpp"

namespace lab3 {
    
    void Troll::action() {
        for(const auto & a : curr_location->actors_in_room) {
            if(a->name().compare(name()) != 0) {
                fight(a);
                return;
            }
        }
    }
    
    std::string Troll::type() {
        return "Troll";
    }
}