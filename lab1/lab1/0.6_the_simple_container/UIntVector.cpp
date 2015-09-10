#include <iostream>
#include "UIntVector.h"

UIntVector::UIntVector()
{
}

UIntVector::UIntVector(size_t size)
{
    vector_size = size;
    first = new unsigned int[size];
    reset();
}

UIntVector::UIntVector(std::initializer_list<unsigned int> list)
{
    vector_size = list.size();
    first = new unsigned int[list.size()];
    for(int i = 0; i < list.size(); i++) {
        //Use pointer arithmetic to dereference the elements in list
        first[i] = *(list.begin() + i);
    }
}

UIntVector::UIntVector(const UIntVector & obj) {
    std::cout << "Copy constructor" << std::endl;
    first = new unsigned int[obj.size()];
    for(int i = 0; i < obj.size(); i++) {
            first[i] = obj[i];
    }
}

unsigned int UIntVector::operator[](const int index) const
{
    if(index < vector_size)
        return first[index];
    else
        throw std::out_of_range("Index out of range");
}

UIntVector::~UIntVector()
{
    delete [] first;
}

void UIntVector::reset()
{
    for(int i = 0; i < vector_size; i++) {
        first[i] = 0;
    }
}

std::size_t UIntVector::size() const
{
    return vector_size;
}

int main() {
    const size_t size = 5;
    UIntVector v1({1, 2, 3, 4, 5}); // copy list-initialization
    UIntVector v(size);
    UIntVector c = v;
    std::cout << v[0] << std::endl;
    std::cout << v[6] << std::endl;
    std::cout << v[3] << std::endl;
    std::cout << v.size() << std::endl;
    return 0;
}
