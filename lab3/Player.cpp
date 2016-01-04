//
//  Player.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Player.hpp"
#include <string>
#include <map>
#include "Room.hpp"
#include <iostream>
namespace lab3 {
    
    
    void Player::print_location() {
        std::cout << "You are in " << curr_location->name() << std::endl;
    }
}
