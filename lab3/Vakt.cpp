
//
//  Vakt.cpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Vakt.hpp"
#include <iostream>
#include <stdlib.h>

namespace lab3 {
    
    void Vakt::action() {
        
        //Fight other actors in room. Don't fight yourself.
        for(const auto & a : curr_location->actors_in_room) {
            if(a->name().compare(name()) != 0) {
                fight(a);
                return;
            }
        }
    }
    
    std::string Vakt::type() {
        return "Vakt";
    }
}