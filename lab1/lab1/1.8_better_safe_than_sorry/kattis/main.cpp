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
    Vector<int> vec(1000, 1024);
    Vector<int> vec2 = {12, 252};
    Vector<int> vec3 = vec;
    Vector<int> vec5 = std::move(std::move(vec2));
    vec.push_back(2048);
    vec.erase(0);

}
