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
void executeComputerClass();
void executeLinkedList();
void generateAndPrintLinkedList(int num_elements);

struct employee {
    int id_number;
    int age;
    float salary;
};

struct node {
    int x;
    node *next;
};

class Computer
{
public:
    Computer();
    ~Computer();
    void setSpeed(int p);
    int readSpeed();
protected:
    int processorSpeed;
};

Computer::Computer()
{
    processorSpeed = 0;
}

Computer::~Computer()
{
    
}

void Computer::setSpeed(int p)
{
    processorSpeed = p;
}

int Computer::readSpeed()
{
    return processorSpeed;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    //executeBasic();
    //executeIO();
    //executeTypecasting();
    //executeComputerClass();
    executeLinkedList();
    
    return 0;
}

void executeLinkedList()
{
   /* node *root;
    node *conductor;
    
    root = new node;
    root -> next = 0;
    root -> x = 12;
    
    conductor = root;
    if(conductor != 0){
        while(conductor -> next != 0)
            conductor = conductor -> next;
    }
    conductor -> next = new node;
    conductor = conductor -> next;
    conductor -> next = 0;
    conductor -> x = 42;
    
    cout << root -> x << "\n";
    cout << root -> next -> x << "\n";*/
    generateAndPrintLinkedList(5);
}

void generateAndPrintLinkedList(int num_elements){
    node *root;
    node *conductor;
    
    root = new node;
    root -> x = rand() % 5;
    root -> next = 0;
    
    conductor = root;
    // Create list
    for(int i = 0; i<num_elements; i++){ // -1 as we create node manually
        conductor -> next = new node;
        conductor = conductor -> next;
        
        conductor -> x = rand() % 5;
        conductor -> next = 0;
    }
    
    conductor = root;
    cout << "[";
    if(conductor != 0){
        while(conductor -> next != 0){
            cout << conductor -> x;
            conductor = conductor -> next;
            if(conductor -> next != 0)
                cout << ", ";
        }
        cout << "]";
    }
}

void executeComputerClass(){
    Computer compute;
    compute.setSpeed(100);
    cout << compute.readSpeed() << "\n";
}

void executeTypecasting(){
    cout << (char)65 << "\n"; // ascii
    
    //create ascii table
    for(int x = 65; x < 91; x++){
        cout << x << ". " << (char)x << "\n";
    }
    
    cout << 3/5 << "\n";
    cout << (float)3/5 << "\n";
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

inline int mult(int x, int y){
    return x*y;
}