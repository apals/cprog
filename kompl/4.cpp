#include <iostream>
class Bil{
    public:
        int x;
        Bil(int y): x(y) {};
        Bil(const Bil&);
        Bil& operator=(const Bil&);
        ~Bil(){};

        bool operator<(const Bil& b) const{
            return(x < b.x);
        }

};

int main(){
    const Bil a(5);
    const Bil b(4);
    std::cout << (a < b) << std::endl;
    std::cout << (b < a) << std::endl;
};
