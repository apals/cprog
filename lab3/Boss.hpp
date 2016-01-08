//
//  Boss.hpp
//  lab3
//
//  Created by Andreas Pålsson on 04/01/16.
//  Copyright © 2016 Andreas Pålsson. All rights reserved.
//

#ifndef Boss_hpp
#define Boss_hpp

#include <stdio.h>
#include "Troll.hpp"

namespace lab3 {
    class Boss : public Troll {
    public:
        Boss(std::string name, Room * room) : Troll(name, room) {}
        virtual std::string type() const;
        virtual void lose_hp(int amt);
        virtual void action();
    };
}

#endif /* Boss_hpp */
