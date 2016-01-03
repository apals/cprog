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
#include "Player.hpp"
namespace lab3 {

    class Game {
    public:
        Game();
        void init();
        bool is_running();
    private:
        void print_story();
        void print_options();
        void parse_input(int input);
        Player * player;
    };
}

#endif /* Game_hpp */
