//
//  Game.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Game.hpp"
#include "Troll.hpp"
#include <iostream>
#include <string>
namespace lab3 {
    
    Game::Game() {
        init();
        print_story();
    }
    
    void Game::init() {
        Room * room1 = new Room("Room 1");
        Room * room2 = new Room("Room 2");
        
        Object * o = new Object("knarck", room1);
        
        room1->neighbors["right"] = room2;
        room2->neighbors["left"] = room1;
        rooms["1"] = room1;
        rooms["2"] = room2;
        
        player = new Player("Player", room1);
        Troll * troll = new Troll("Troll1", room2);
        actors.push_back(player);
        actors.push_back(troll);
    }
    
    bool Game::is_running() {
        return player->hp() > 0;
    }
    
    void Game::print_story() {
        std::cout << " i am the story of death and destruciton together with baracka obama i will rule the world mvh" << std::endl;
    }
    
    void Game::parse_input(int input) {
        
    }
    
    void Game::play() {
    
        for(auto a : actors) {
            if(a->is_alive()) {
                a->action();
            } else {
                actors.erase(std::remove(actors.begin(), actors.end(), a), actors.end());
                delete a;
            }
        }
        
        
    }
    
    std::map<std::string, Room *> Game::GET_ALL_ROOMS() {
        return rooms;
    }
}
