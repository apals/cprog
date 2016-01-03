//
//  Actor.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <stdio.h>
#include "Room.hpp"
namespace lab3 {
    
    class Actor {
    public:
        Actor() {};
        int hp();
        Room * location();
    protected:
        int curr_hp;
        Room * curr_location;
    };
    
   
    
}
#endif /* Actor_hpp */
