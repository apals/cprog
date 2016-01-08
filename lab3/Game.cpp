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
#include "Gainomax.hpp"
#include "Vakt.hpp"
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
        Object * addeskeys = new Object("addepsnycklar");
        Gainomax * gainomax = new Gainomax("Gainomax");
        
        LockedRoom * addep = new LockedRoom("Adde Ps lya", "Du står i Adde Ps hem. Det kanske ligger en Gainomax under en av soffkuddarna...",  std::vector<Object *>{});
        Room * stureskon = new Room("Kön till Sturecompagniet", "Här står fjorton hundra hormonstinna 19-åringar vars mål ikväll är att spendera pappas pengar");
        Room * odenplan = new Room("Odenplan", "Gu va trevligt här på OdenP!");
        Room * stureplan = new Room("Stureplan", "u know sturep");
        Room * seven_eleven = new Room("7Eleven", "sleven");
        LockedRoom * kb = new LockedRoom("KBs knarkarkvart", "Kb", std::vector<Object *>{knark});
        LockedRoom * stures = new LockedRoom("Sturecompagniet", "thiensa", std::vector<Object *>{vaktitem, cigg});
        SmokeRoom * rokruta = new SmokeRoom("Rökruta", "here u smoke lol");
        
        kb->set_npc_entrance("Mange");
        addep->set_npc_entrance("DoggeDoggelito");
        kb->set_npc_entrance("DoggeDoggelito");
        stures->set_npc_entrance("DoggeDoggelito");
        
        player = new Player("Player", addep);
        Boss * troll = new Boss("Mange", kb);
        Vakt * vakt = new Vakt("Vakt", stureskon);
        Troll * dogge = new Troll("DoggeDoggelito", seven_eleven);
        
        
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
        gainomax->set_location(addep);
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
        rooms.push_back(rokruta);
        
        objects.push_back(knark);
        objects.push_back(vaktitem);
        objects.push_back(cigg);
        objects.push_back(addeskeys);
        objects.push_back(gainomax);
        
        
        actors.push_back(player);
        actors.push_back(troll);
        actors.push_back(vakt);
        actors.push_back(dogge);
    }
    
    bool Game::is_running() {
        return player->hp() > 0 && running;
    }
    
    void Game::print_story() {
        std::cout << "Ken Ring har gått vilse i Stockholm och vill inget hellre än att komma hem. Hjälp honom hitta knarket och ta sig tillbaka till Hässelby" << std::endl;
    }
    
    void Game::play() {
        
        for(auto a : actors) {
            
            if(a->is_alive()) {
                a->action();
            } else {
                if(a->name().compare("Mange") == 0) {
                    finish();
                }
                //remove actor from room
                a->location()->leave(a);
                actors.erase(std::remove(actors.begin(), actors.end(), a), actors.end());
                delete a;
            }
        }
        
        
    }
    
    void Game::finish() {
        running = false;
    }
    
    Game::~Game() {
        for(auto const & a : actors) {
            delete a;
        }
        
        for(auto const & a : objects) {
            delete a;
        }
        
        for(auto const & a : rooms) {
            delete a;
        }
    }
    
    
}
