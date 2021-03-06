#include <iostream>
#include <ios>
#include <sstream>

#include "hello.h"

void hello (const char * name, int count) {
    if(count == -1)
        std::cerr << name << std::endl;
    /* Check if 0 */
    else if(count == 0)
        return;
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
        std::cerr << "error: Too many arguments!" << std::endl;

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
                int i = 0;
                if(in >> i && in.eof())
                {
                    if(atoi(argv[2]) < 0){
                    std::cerr << "error: 2nd argument must be an integral greater than zero!" << std::endl;
                    return std::make_pair("error", -1);
                    }
                    return std::make_pair(argv[1], atoi(argv[2]));
                }
                else {
                    std::cerr << "error: 2nd argument must be an integral greater than zero!" << std::endl;
                    return std::make_pair("error", -1);
                }
                break;
            }
        default:
            return std::make_pair("undefined error", -1);
    }
}
