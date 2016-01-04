//
//  Troll.hpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Troll_hpp
#define Troll_hpp

#include <stdio.h>
#include "Actor.hpp"

namespace lab3 {
    
    class Troll : public Actor {
    public:
        Troll(std::string name, Room * room) : Actor(name, room) {}
        virtual void action();
        virtual std::string type();
        
    };
    
}

#endif /* Troll_hpp */
