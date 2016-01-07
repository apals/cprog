//
//  Object.cpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Object.hpp"
#include <iostream>
#include "Actor.hpp"
namespace lab3 {
    
    Object::Object(std::string name) : curr_name(name){}
    
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
    
    void Object::set_location(Room *location){
        curr_location = location;
        curr_location -> enter(this);
    }
    
    bool Object::use(Actor * a) {
        std::cout << "Nothing happens.." << std::endl;
        return false;
    }
    
    Object::~Object() {
        
    }
}
