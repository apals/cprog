//
//  main.cpp
//  lab1
//
//  Created by Andreas Pålsson on 31/08/15.
//  Copyright (c) 2015 Andreas Pålsson. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int mult(int x, int y);
void executeBasic();
void executeIO();
void executeTypecasting();

struct employee {
    int id_number;
    int age;
    float salary;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    //executeBasic();
    //executeIO();
    executeTypecasting();
    return 0;
}

void executeTypecasting(){
    cout << (char)65 << "\n"; // ascii
    
    //create ascii table
    for(int x = 65; x < 91; x++){
        cout << x << ". " << (char)x << "\n";
    }
    
    cin.get();
}

void executeIO(){
    string filename = "write.txt";
    ofstream write_file(filename, ios::trunc);
    write_file << "Write this text!";
    write_file.close();
    
    ifstream file(filename);
    if(!file.is_open()){
        cout << "File is already open!";
        
    } else {
        string str;
        file >> str;
        cout << str;
    }
}

void executeBasic(){
    /*
     int number = 0;
     cout << "Please enter number: ";
     cin >> number;
     cout << "You entered: " << number << "\n";
     
     for(int x = 0; x<number; x++){
     cout << x << "\n";
     }
     
     int x = 0;
     
     do { // Will run at least once
     cout << "Enter number: ";
     cin >> x;
     } while (x != 0);
     
     int num1, num2;
     cout << "Enter two numbers to multiply seperated by whitespace: ";
     cin >> num1 >> num2;
     cout << "Multipled value: " << mult(num1, num2) << "\n";
     
     switch (rand() % 3 + 1) {
     case 1:
     cout << "1";
     break;
     case 2:
     cout << "2";
     break;
     case 3:
     cout << "3";
     break;
     default:
     break;
     }
     
     int *pointer, nonpointer;
     nonpointer = 0;
     pointer = &nonpointer;
     cout << "Pointer: " << *pointer << ", nonpointer: " << nonpointer << "\n";
     *pointer = 5;
     cout << "Pointer: " << *pointer << ", nonpointer: " << nonpointer << "\n";
     nonpointer = 6;
     cout << "Pointer: " << *pointer << ", nonpointer: " << nonpointer << "\n";
     
     int *ptr = new int;
     *ptr = 5;
     cout << *ptr;
     delete ptr;
     ptr = 0; // good habit to point ptr to 0x000000
     
     
     employee sarah;
     employee *test;
     sarah.age = 33;
     sarah.salary = 32.3333;
     sarah.id_number = 1;
     
     test = &sarah; // assign sarah address to test
     cout << test -> age; // get age val of test
     
     int x, y, arraySize = 8, array[arraySize][arraySize];
     
     for(x = 0; x<arraySize; x++){
     for( y = 0; y<arraySize; y++){
     array[x][y] = x*y;
     }
     }
     cout << "Array indicides: \n";
     for(x = 0; x<arraySize; x++){
     for(y = 0; y<arraySize; y++)
     cout << array[x][y] << "\t";
     //            cout << "["<<x<<"]["<<y<<"]=" << array[x][y] << " ";
     cout << "\n";
     }
     
     char name[2];
     cout << sizeof(name);
     cin.getline(name, 5);
     cout << sizeof(name);
     cout << name;
     */
}

int mult(int x, int y){
    return x*y;
}