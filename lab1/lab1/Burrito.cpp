//
//  Burrito.cpp
//  lab1
//
//  Created by Oscar Alsing on 01/09/15.
//  Copyright (c) 2015 Andreas Pålsson. All rights reserved.
//

#include "Burrito.h"
#include <iostream>

using namespace std;

Burrito::Burrito()
{
    cout << "this is mah constructor of death \n";
    cout << "coolio bror nu kör vi!! \n";
    price = 10;
}

int Burrito::getPrice()
{
    return price;
}

void Burrito::generateAmazingBurritoOfHangoverCuring()
{
    srand(time(0));
    string fillingList[] = {"Chocolate", "Chicken", "Feta", "Children", "Mince", "Beef"};
    string typeList[] = {"Wrap", "Pancake wrap", "Burrito", "Sandwich"};
    string awesomeList[] = {"Death", "Doom", "P"};
    
    cout << fillingList[rand() % sizeof(fillingList)/sizeof(fillingList[0])] << " "
    << typeList[rand() % sizeof(typeList)/sizeof(typeList[0])] << " of "
    << awesomeList[rand () % sizeof(awesomeList)/(sizeof(awesomeList[0]))] << "\n";
}