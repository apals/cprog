//
//  Player.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Actor.hpp"
namespace lab3 {
    
    class Player : public Actor {
    public:
        Player(std::string name, Room * room) : Actor(name, room) {
            curr_hp = 100;
        }
        virtual void action();
        virtual std::string type();
    };
}

#endif /* Player_hpp */
