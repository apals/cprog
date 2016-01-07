//
//  Game.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Actor.hpp"

namespace lab3 {

    class Game {
    public:
        Game();
        ~Game();
        void init();
        bool is_running();
        std::map<std::string, Room *> GET_ALL_ROOMS();
        void play();
        void finish();
    private:
        void print_story();
        Player * player;
        std::vector<Room *> rooms;
        std::vector<Actor *> actors;
        std::vector<Object *> objects;
        bool running = true;
    };
    
}

#endif /* Game_hpp */
