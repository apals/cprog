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
    
    
    
    void Player::action() {
        
        
        print_location();
        curr_location->print_directions();
        curr_location->print_actors_in_room();
        curr_location->print_objects_in_room();
        print_inventory();
        
        std::cout << "> ";
        std::string a;
        std::getline(std::cin, a);
        std::vector<std::string> tokens = lab3::split(a, ' ');
        
        if(tokens[0].compare("go") == 0) {
            go(tokens[1]);
        }
        
        else if(tokens[0].compare("fight") == 0) {
            
            /**
             * FIGHTING
             */
            //find whoever the user is targeting
            for(const auto & a : curr_location->actors_in_room) {
                if(tokens[1].compare(a->name()) == 0) {
                    fight(a);
                    return;
                }
            }
            
            //not found
            std::cout << "hwat u doing u cant fight " << tokens[1] << std::endl;
            
            /**
             * END FIGHTING
             */
        }
        
        else if(tokens[0].compare("pickup") == 0) {
            
            for(const auto & a : curr_location->objects_in_room) {
                if(tokens[1].compare(a->name()) == 0) {
                    pick_up(a);
                    return;
                }
            }
            
            //not found
            std::cout << "hwat u doing u cant pickup " << tokens[1] << std::endl;
            
        }
    }
    
    std::string Player::type() {
        return "Player";
    }
    
    
    
    
    
}
