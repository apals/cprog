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
#include <vector>
#include <sstream>
#include "Utils.hpp"

namespace lab3 {
    
    void Player::print_location() {
        std::cout << "You are in " << curr_location->name() << std::endl;
    }
    
    void Player::action() {
        std::cout << "> ";
        std::string a;
        std::getline(std::cin, a);
        std::vector<std::string> tokens = lab3::split(a, ' ');
        if(tokens[0].compare("go") == 0) {
            go(tokens[1]);
        }
    }
    
    
   
    

}
