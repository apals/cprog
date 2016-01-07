//
//  Vakt.hpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Vakt_hpp
#define Vakt_hpp

#include <stdio.h>
#include "Actor.hpp"
#include "Room.hpp"

namespace lab3 {
    class Vakt : public Actor {
    public:
        Vakt(std::string name, Room * room) : Actor(name, room) {}
        virtual void action();
        virtual std::string type();
    };
}

#endif /* Vakt_hpp */
