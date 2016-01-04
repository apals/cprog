//
//  Container.hpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include <stdio.h>
#include "Object.hpp"

namespace lab3 {
    class Container : public Object {
    public:
        int hold_weight();
    };
}


#endif /* Container_hpp */
