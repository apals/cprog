#include <iostream>
#include <stdexcept>
#include "kth_cprog_simple_container.hpp"

UIntVector::UIntVector()
{
    vector_size = 0;
    first = new unsigned int;
}

UIntVector::UIntVector(const std::size_t size)
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

UIntVector::UIntVector(UIntVector && obj) {
    std::cout << "move constructor" << std::endl;
    vector_size = obj.vector_size;
    first = obj.first;

    obj.first = nullptr;

}

UIntVector& UIntVector::operator=(UIntVector && other) {
    std::cout << "move assignment operator" << std::endl;
    vector_size = std::move(other.vector_size);
    first = std::move(other.first);
    return *this;
}

unsigned int& UIntVector::operator[](const size_t index) 
{
    std::cout << "INTE CONST MADDAFAKKA" << std::endl;
    if(index < vector_size)
        return first[index];
    throw std::out_of_range("Index out of range");
}

const unsigned int& UIntVector::operator[](const size_t index) const
{
    std::cout << "CONST MADDAFAKKA" << std::endl;
    if(index < vector_size)
        return first[index];
    else
        throw std::out_of_range("Index out of range");
}

UIntVector& UIntVector::operator=(const UIntVector& other)
{
    UIntVector tmp(other);
    std::swap(vector_size, tmp.vector_size);
    std::swap(first, tmp.first);
    return *this;
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

void printVector(UIntVector& v)
{
    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << ", ";
    std::cout << std::endl;
}
