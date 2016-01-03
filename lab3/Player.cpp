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
    Player::Player() : Actor() {
        std::map<std::string, Room*> ooms = GET_ALL_ROOMS();

        Room * location = GET_ALL_ROOMS()["1"];
        curr_location = location;
    }
    
    void Player::print_location() {
        std::cout << "You are in " << curr_location->get_name() << std::endl;
    }
}
