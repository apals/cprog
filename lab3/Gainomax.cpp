//
//  Gainomax.cpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Gainomax.hpp"
#include <iostream>

namespace lab3 {
    bool Gainomax::use(Actor * a) {
        std::cout << a->name() << " just used " << name() << ". Your HP increased by 10! " << std::endl;
        a->set_hp(a->hp() + 10);
        return true;
    }
    
    Gainomax::~Gainomax() {
        
    }
}
