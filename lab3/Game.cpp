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
        std::cout << "1. die" << std::endl;
        std::cout << "2. not die " << std::endl;
        int a;
        std::cin >> a;
        std::cout << a << std::endl;
        parse_input(a);
    }
}
