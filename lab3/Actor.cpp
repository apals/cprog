//
//  Actor.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Actor.hpp"
#include <string>
#include <iostream>
namespace lab3 {
    
    Actor::Actor(std::string name, Room * location) : curr_location(location), curr_name(name) {
        inventory = new Container("Backpack");
        curr_location->enter(this);
    };
    
    int Actor::hp() {
        return curr_hp;
    }
    
    Room * Actor::location() {
        return curr_location;
    }
    
    std::string Actor::name() {
        return curr_name;
    }
    
    void Actor::action() {
        
    }
    
    void Actor::go(std::string direction) {
        std::map<std::string, Room * >::iterator it = curr_location->neighbors.find(direction);
        
        //If room to direction exists
        if(it != curr_location->neighbors.end()){
            
            //
            if (curr_location->neighbors[direction]->enter(this)) {
                curr_location->leave(this);
                curr_location = curr_location->neighbors[direction];
            } else {
                //print error msg only for player
                if(name().compare("Player") == 0)
                    std::cout << "For some reason you can't enter that place..." << std::endl;
            }
            
            
        } else {
            std::cout << "what r u doing u stupid thats just miffo" << std::endl;
        }
    }
    
    std::vector<Object *> Actor::get_inventory() {
        return inventory->items();
    }
    
    std::string Actor::type() {
        return "Actor";
    }
    
    void Actor::set_hp(int hp) {
        curr_hp = hp;
        std::cout << name() << "'s HP is now " << curr_hp << std::endl;
    }
    
    void Actor::fight(Actor * a) {
        std::cout << name() << " is trying to fight " << a->name() << std::endl;
        a->lose_hp(5);
        std::cout << std::endl;
    }
    
    void Actor::talk_to(Actor * a) {
        
    }
    void Actor::pick_up(Object * o) {
        if(inventory->add_item(o)) {
            curr_location->leave(o);
        }
        
    }
    void Actor::drop(Object * o) {
        curr_location->enter(o);
        inventory->remove_item(o);
    }
    
    void Actor::use(Object * o) {
        if(o->use(this)) {
            inventory->remove_item(o);
        }
    }
    
    void Actor::lose_hp(int amt) {
        curr_hp -= amt;
        std::cout << "Ouch, " << name() << " just got hit! Remaining HP: " << curr_hp << std::endl;
        
        if (curr_hp <= 0) {
            std::cout << name() << " just died... " << std::endl;
            
            for(auto const & item : inventory->items()) {
                drop(item);
            }
        }
    }
    
    bool Actor::is_alive() {
        return curr_hp > 0;
    }
    
    void Actor::print_location() {
        std::cout << name() << " is in " << curr_location->name() << std::endl;
        std::cout << std::endl;
    }
    
    void Actor::print_inventory() {
        std::cout << "Inventory: " << std::endl;
        std::cout << '\t' << inventory->name() << ":" << std::endl;
        for(const auto & i : get_inventory()) {
            std::cout << "\t\t" << i->name() << std::endl;
        }
        std::cout << std::endl;
    }
    
    Actor::~Actor() {
        delete inventory;
    }
}