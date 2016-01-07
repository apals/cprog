//
//  LockedRoom.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "LockedRoom.hpp"
#include <algorithm>

namespace lab3 {
    
    bool LockedRoom::enter(Actor * a) {
        
        //only stop the player (in this case type Player)
        if(a->name().compare("Player") != 0) {
            actors_in_room.push_back(a);
            return true;
        }
        
        
        /**
         * CHECK IF ACTOR HAS ALL NECESSARY ITEMS
         */
        bool missing_item = false;
        for(auto const & item : needed_items) {
            if(std::find(a->get_inventory().begin(), a->get_inventory().end(), item) != a->get_inventory().end()) {
                
            } else {
                missing_item = true;
                break;
            }
        }
        if(!missing_item) {
            actors_in_room.push_back(a);
            return true;
        }
        /**
         * END ITEM CHECK
         */
        
        
        //they didnt have the key :<
        return false;
    }
}