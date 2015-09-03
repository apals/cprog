#include <iostream>
#include <ios>
#include <sstream>

#include "hello.h"

void hello (const char * name, int count) {
    if(count == 0){
    }
    else {
        std::cout << "Hello, ";
        for(int i = 0; i<count; i++){
            std::cout << name;
            if(i < count-1)
                std::cout << " ";
        }
        std::cout << "!" << std::endl;
    }
}

std::pair<const char *, int> parse_args (int argc, char * argv[]) {
    /* Error handling */
    if(argc > 3)
        std::cout << "error: Too many arguments!" << std::endl;

    /* No errors -> Switch */
    switch(argc){
        case 1:
            return std::make_pair("world", 1);
            break;
        case 2:
            return std::make_pair(argv[1], 1);
            break;
        case 3:
            /* Begin case scope to declare variables */
            {
                std::istringstream in(argv[2]);
                int i;
                if(in >> i && in.eof())
                    return std::make_pair(argv[1], atoi(argv[2]));
                else {
                    std::cout << "error: 2nd argument must be an integral greater than zero!" << std::endl;
                    return std::make_pair("error", -1);
                }
                break;
            }
        default:
            return std::make_pair("error", -1);
    }
}
