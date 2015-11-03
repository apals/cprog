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
    Vector<int> vec2 = {12, 252};
    Vector<int> vec5 = std::move(std::move(vec2));
    Vector<int> vec(2);
    vec.insert(0, 1);
    vec.insert(0, 1);
    vec.insert(0, 1);
    vec.insert(0, 1);
    vec.insert(0, 1);

}
