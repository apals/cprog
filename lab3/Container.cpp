//
//  Container.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Container.hpp"
#include <iostream>

namespace lab3 {
    int Container::hold_weight() {
        return 5;
    }
    
    void Container::add_item(Object * o) {
        curr_items.push_back(o);
    }
    
    void Container::remove_item(Object * o) {
        curr_items.erase(std::remove(curr_items.begin(), curr_items.end(), o), curr_items.end());
    }
    
    std::vector<Object *> Container::items() {
        return curr_items;
    }
    
    std::string Container::name() {
        return curr_name;
    }
}