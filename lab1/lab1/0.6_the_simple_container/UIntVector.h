#ifndef UINTVECTOR
#define UINTVECTOR

#include <cstring>

class UIntVector {

    private:
        size_t size;
    public:
        UIntVector();
        UIntVector(size_t);
        UIntVector(std::initializer_list<unsigned int>);
};

#endif
