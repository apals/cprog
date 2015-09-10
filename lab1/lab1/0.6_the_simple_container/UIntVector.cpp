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
    vector_size = obj.size();
    for(int i = 0; i < obj.size(); i++) {
        first[i] = obj[i];
    }
}

UIntVector::UIntVector(const UIntVector && obj) {
    std::cout << "move constructor" << std::endl;
}

UIntVector& UIntVector::operator=(const UIntVector && other) {
    std::cout << "move assignment operator" << std::endl;
    vector_size = std::move(other.vector_size);
    first = std::move(other.first);
    return *this;
}

unsigned int& UIntVector::operator[](int index) 
{
    if(index < vector_size || index < 0)
        return first[index];
    throw std::out_of_range("Index out of range");
}

UIntVector& UIntVector::operator=(const UIntVector& other)
{
    UIntVector tmp(other);
    std::cout << "jag är en dIck" << std::endl;
    std::swap(vector_size, tmp.vector_size);
    std::swap(first, tmp.first);
    return *this;
}

const unsigned int& UIntVector::operator[](int index) const
{
    if(index < vector_size || index < 0)
        return first[index];
    else
        throw std::out_of_range("Index out of range");
}


UIntVector::~UIntVector()
{
    std::cout << "destructor" << std::endl;
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


    std::cout << "================" << std::endl;
    std::cout << "================" << std::endl;
    const UIntVector v2(size + 2);
    std::cout << "hejhej" << std::endl;
    v1[4] = 7;
    v1[4]++;
    std::cout << "v1[4] == " << v1[4] << std::endl;
    UIntVector m1, m2;
    m1 = std::move(m2);
    return 0;
}
