//
//  SmokeRoom.cpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "SmokeRoom.hpp"
#include <iostream>

namespace lab3 {
    bool SmokeRoom::enter(Actor * a) {
        actors_in_room.push_back(a);
        a->lose_hp(5);
        std::cout << a->name() << " walked into smoke.. Ouch! Remaining HP: " << a->hp() << std::endl;
        return true;
    }
}