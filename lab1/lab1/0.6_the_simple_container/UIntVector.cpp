#include <iostream>
#include "UIntVector.h"

UIntVector::UIntVector()
{
}

UIntVector::UIntVector(size_t size)
{
    first = new unsigned int[size];
}

UIntVector::UIntVector(std::initializer_list<unsigned int> list)
{
}

unsigned int UIntVector::operator[](const int index)
{
    return first[index];
}

UIntVector::~UIntVector()
{
}

void UIntVector::reset()
{
    for(int i = 0; i < vector_size; i++) {
    }
}

std::size_t UIntVector::size()
{
    return vector_size;
}

int main() {
    const size_t size = 5;
    UIntVector v(size);
    std::cout << v[0] << std::endl;
    std::cout << v[6] << std::endl;
    return 0;
}
