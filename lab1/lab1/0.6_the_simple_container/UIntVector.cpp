#include <iostream>
#include "UIntVector.h"

UIntVector::UIntVector()
{
}

UIntVector::UIntVector(size_t size)
{
    first = new unsigned int * [size];
    std::cout << "allocated first ***" << std::endl;
    for(int i = 0; i < size; i++) {
        first[i] = new unsigned int;
        std::cout << "ALLOCATED AN INTE" << std::endl;
    }
}

UIntVector::UIntVector(std::initializer_list<unsigned int> list)
{
}

void UIntVector::reset()
{
}

std::size_t UIntVector::size()
{
    return vector_size;
}

int main() {
    const size_t size = 5;
    UIntVector v(size);
    return 0;
}
