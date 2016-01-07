//
//  Game.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Game.hpp"
#include "Troll.hpp"
#include "Boss.hpp"
#include "LockedRoom.hpp"
#include "SmokeRoom.hpp"
#include <iostream>
#include <string>
namespace lab3 {
    
    Game::Game() {
        init();
        print_story();
    }
    
    void Game::init() {
        
        Object * knark = new Object("knark");
        Object * vaktitem = new Object("vaktbricka");
        Object * cigg = new Object("cigarettes");
        Object * addeskeys = new Object("addeps nycklar");
        
        
        //these are memory leaks right????? since we can't reference room1,2 or o from outside init scope
        LockedRoom * addep = new LockedRoom("Adde Ps lya", std::vector<Object *>{addeskeys});
        Room * stureskon = new Room("Kön till Sturecompagniet");
        Room * odenplan = new Room("Odenplan");
        Room * stureplan = new Room("Stureplan");
        Room * seven_eleven = new Room("7Eleven");
        LockedRoom * kb = new LockedRoom("KBs knarkarkvart", std::vector<Object *>{knark});
        LockedRoom * stures = new LockedRoom("Sturecompagniet", std::vector<Object *>{vaktitem, cigg});
        SmokeRoom * rokruta = new SmokeRoom("Rökruta");
        
        kb -> set_npc_entrance("Mange");
        
        player = new Player("Player", addep);
        Boss * troll = new Boss("Mange", kb);
        Troll * vakt = new Troll("Vakt", stureskon);
        
        
        addep->neighbors["west"] = odenplan;
        odenplan->neighbors["east"] = addep;
        
        odenplan->neighbors["west"] = kb;
        kb->neighbors["east"] = odenplan;
        
        addep->neighbors["east"] = stureskon;
        stureskon->neighbors["west"] = addep;
        
        stureskon->neighbors["entrance"] = stures;
        stures->neighbors["out"] = stureskon;
        
        stures->neighbors["smoke"] = rokruta;
        rokruta->neighbors["in"] = stures;
        
        stureskon->neighbors["east"] = stureplan;
        stureplan->neighbors["west"] = stureskon;
        
        stureplan->neighbors["east"] = seven_eleven;
        seven_eleven->neighbors["west"] = stureplan;
        
        knark->set_location(stures);
        vaktitem->set_location(stureskon);
        vakt->pick_up(vaktitem);
        
        addeskeys -> set_location(addep);
        player->pick_up(addeskeys);
        
        cigg->set_location(seven_eleven);
        
        rooms.push_back(addep);
        rooms.push_back(stureskon);
        rooms.push_back(odenplan);
        rooms.push_back(kb);
        rooms.push_back(stures);
        rooms.push_back(seven_eleven);
        rooms.push_back(stureplan);
        
        objects.push_back(knark);
        objects.push_back(vaktitem);
        objects.push_back(cigg);
        objects.push_back(addeskeys);
        
        
        actors.push_back(player);
        actors.push_back(troll);
        actors.push_back(vakt);
    }
    
    bool Game::is_running() {
        return player->hp() > 0;
    }
    
    void Game::print_story() {
        std::cout << " i am the story of death and destruciton together with baracka obama i will rule the world mvh" << std::endl;
    }
    
    void Game::play() {
        
        for(auto a : actors) {
            
            if(a->is_alive()) {
                a->action();
            } else {
                //remove actor from room
                a->location()->leave(a);
                actors.erase(std::remove(actors.begin(), actors.end(), a), actors.end());
                delete a;
            }
        }
        
        
    }
    
}
