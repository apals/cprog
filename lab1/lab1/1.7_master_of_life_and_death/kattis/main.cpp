#include "Vector.hpp"
/*
struct T1 {
    public:
        static unsigned int object_count;
        T1()            { ++object_count; };
        T1(T1 const&)   { ++object_count; };
        ~T1()           { --object_count; };
};

unsigned int T1::object_count = 0;

int main () {
    {
        Vector<T1> v1 (3); 
        assert (T1::object_count == 3 && v1.capacity () >= 3);
        Vector<T1> v2; assert (T1::object_count == 3);
        v1.push_back (T1{}); assert (T1::object_count == 4 && v1.capacity () >= 4);
        v2 = v1; 
        assert (T1::object_count == 8);
        v2.erase (1); assert (T1::object_count == 7);
        v2.erase (1); assert (T1::object_count == 6);
    }
    assert (T1::object_count == 0);
}
*/
