//
//  Game.cpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include <string>
namespace lab3 {
    
    Game::Game() {
        init();
        print_story();
        print_options();
    }

    void Game::init() {
        Room * room1 = new Room("Room 1");
        Room * room2 = new Room("Room 2");
        
        room1->neighbors["right"] = room2;
        room2->neighbors["left"] = room1;
        rooms["1"] = room1;
        rooms["2"] = room2;
        
        //run this line after creating rooms
        player = new Player(room1);
        actors.push_back(player);
    }
    
    bool Game::is_running() {
        return true;
    }
    
    void Game::print_story() {
        std::cout << " i am the story of death and destruciton together with baracka obama i will rule the world mvh" << std::endl;
    }
    
    void Game::parse_input(int input) {
        
    }
    
    void Game::print_options() {
        player->print_location();
        Room * player_location = player->location();
        player_location->directions();
        /*for(auto const &ent1 : player_location->directions()) {
            std::cout << ent1.first << " : " << ent1.second->get_name() << std::endl;
        }*/
        
        
        int a;
        std::cin >> a;
        std::cout << a << std::endl;
        parse_input(a);
    }
    
    std::map<std::string, Room *> Game::GET_ALL_ROOMS() {
        return rooms;
    }
}
