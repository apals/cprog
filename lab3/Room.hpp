//
//  Room.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <map>
#include <string>
#include "StartingRoom.hpp"

namespace lab3 {
    
    class Room {
    public:
        Room(std::string name);
        virtual std::map<std::string, Room> get_adjacent_rooms() = 0;
        std::string get_name();
    private:
        std::string room_name;
    };
    
    
    std::map<std::string, Room> GET_ALL_ROOMS() {
        StartingRoom * startingRoom = new StartingRoom("koK");
        
        
    }
    
}

#endif /* Room_hpp */
