#include "Vector.hpp"
#include <string>
struct T1 {
    public:
        static unsigned int object_count;
        T1()            { ++object_count; };
        T1(T1 const&)   { ++object_count; };
        ~T1()           { --object_count; };
};

unsigned int T1::object_count = 0;
int main () {
    Vector<int> a;
//    std::cout << a[1] << std::endl;
    //a[1] = 42;
    a.reset();
    a.insert(0, 123);
    a.insert(0, 321);
    a.insert(0, 42);
    a.insert(0, 100);
    std::cout << a[0] << " : " <<a[1]<<" : " << a[2] << ":  " <<a[3] << std::endl;
    a.erase(0);
    a.erase(0);
    a.erase(0);
    std::cout << a[0] << std::endl;

}
