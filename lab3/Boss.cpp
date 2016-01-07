//
//  Boss.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Boss.hpp"
#include <iostream>

namespace lab3 {
    
    std::string Boss::type() {
        return "Boss";
    }
    
    void Boss::lose_hp(int amt) {
        curr_hp -= amt;
        std::cout << "Ouch, " << name() << " just got hit! Remaining HP: " << curr_hp << std::endl;
        if(curr_hp <= 0) {
            std::cout << "You defeated " << name() << ", you deserve to win." << std::endl;
            exit(0);
        }
    }
    
    void Boss::action() {
        for(const auto & a : curr_location->actors_in_room) {
            if(a->name().compare(name()) != 0) {
                fight(a);
                return;
            }
        }
    }
}