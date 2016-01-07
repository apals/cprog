//
//  Gainomax.hpp
//  lab3
//
//  Created by Andreas Pålsson on 07/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Gainomax_hpp
#define Gainomax_hpp

#include <stdio.h>
#include "Object.hpp"

namespace lab3 {
    class Gainomax : public Object {
    public:
        Gainomax(std::string name) : Object(name) {}
        virtual ~Gainomax();
        virtual bool use(Actor * a);
    };
}

#endif /* Gainomax_hpp */
