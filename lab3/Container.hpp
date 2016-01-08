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
#include <vector>
#include "Object.hpp"

namespace lab3 {
    
    class Object;
    
    class Container {
    public:
        Container(std::string name) : curr_name(name) {};
        int hold_weight() const;
        bool add_item(Object * o);
        void remove_item(Object * o);
        std::vector<Object *> items();
        std::string name();
        
    private:
        std::vector<Object *> curr_items;
        std::string curr_name;
    };
}


#endif /* Container_hpp */
