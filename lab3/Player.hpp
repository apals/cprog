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
        Player(Room * room) : Actor(room) {}
        void print_location();
    };
}

#endif /* Player_hpp */
