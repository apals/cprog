//
//  Troll.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "Troll.hpp"

namespace lab3 {
    
    void Troll::action() {
        
        //Fight other actors in room. Don't fight yourself.
        for(const auto & a : curr_location->actors_in_room) {
            if(a->name().compare(name()) != 0) {
                fight(a);
                return;
            }
        }
        
        //Go to random adjacent room
        size_t neighbors_size = curr_location->neighbors.size();
        srand(time(NULL));
        int index = rand() % neighbors_size;
        int i = 0;
        for(auto const &ent1 : curr_location->neighbors) {
            if(i == index) {
                go(ent1.first);
                std::cout << name() << " went to " << ent1.second->name() << std::endl;
                return;
            }
            i++;
        }
    }
    
    std::string Troll::type() {
        return "Troll";
    }
}