//
//  StartingRoom.hpp
//  lab3
//
//  Created by Andreas Pålsson on 02/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef StartingRoom_hpp
#define StartingRoom_hpp

#include "Room.hpp"
#include <map>


namespace lab3 {

    class StartingRoom : public Room {
    public:
        StartingRoom(std::string name);
        std::map<std::string, Room *> get_adjacent_rooms();
        
    };
    
    
}

#endif /* StartingRoom_hpp */
