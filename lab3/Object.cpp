//
//  Object.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Object.hpp"
namespace lab3 {
    
    Object::Object(std::string name, Room * location) : curr_name(name), curr_location(location) {
        curr_location->enter(this);
    }
    
    int Object::weight() {
        return 3;
    }
    
    int Object::volume() {
        return 2;
    }
    
    int Object::price() {
        return 2;
    }
    
    std::string Object::name() {
        return curr_name;
    }
}
