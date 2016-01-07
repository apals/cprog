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
#include <iostream>
#include <string>
namespace lab3 {
    
    Game::Game() {
        init();
        print_story();
    }
    
    void Game::init() {
        
        //these are memory leaks right????? since we can't reference room1,2 or o from outside init scope
        Room * addep = new Room("Adde Ps lya");
        
        
        Room * stures = new Room("Sturecompagniet");
        Object * o = new Object("knarck", stures);
        LockedRoom * kb = new LockedRoom("KBs knarkarkvart", std::vector<Object *>{o});

        
        Room * odenplan = new Room("Odenplan");
        
        
        addep->neighbors["west"] = odenplan;
        odenplan->neighbors["east"] = addep;
        
        odenplan->neighbors["west"] = kb;
        kb->neighbors["east"] = odenplan;
        
        addep->neighbors["east"] = stures;
        stures->neighbors["west"] = addep;
        
        rooms["1"] = addep;
        rooms["2"] = stures;
        
        player = new Player("Player", addep);
        Boss * troll = new Boss("Mange", kb);
        Troll * vakt = new Troll("Vakt", stures);
        
        
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
    
    std::map<std::string, Room *> Game::GET_ALL_ROOMS() {
        return rooms;
    }
}
