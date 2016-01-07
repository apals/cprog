//
//  Gainomax.cpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Gainomax.hpp"

namespace lab3 {
    bool Gainomax::use(Actor * a) {
        a->lose_hp(10);
        return true;
    }
    
    Gainomax::~Gainomax() {
        
    }
}
