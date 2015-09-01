//
//  Burrito.h
//  lab1
//
//  Created by Oscar Alsing on 01/09/15.
//  Copyright (c) 2015 Andreas Pålsson. All rights reserved.
//

#ifndef __lab1__Burrito__
#define __lab1__Burrito__

#include <stdio.h>

class Burrito
{
public:
    Burrito();
    int getPrice();
    void generateAmazingBurritoOfHangoverCuring();
private:
    int price, stockAm, cookTime;
    char name[];
};

#endif /* defined(__lab1__Burrito__) */
