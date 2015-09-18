#include <iostream>
#include <stdexcept>
#include "kth_cprog_simple_container.hpp"

UIntVector::UIntVector()
{
    vector_size = 0;
    first = new unsigned int[vector_size];
}

UIntVector::UIntVector(const std::size_t size)
{
    vector_size = size;
    first = new unsigned int[vector_size];
    reset();
}

UIntVector::UIntVector(std::initializer_list<unsigned int> list)
{
    vector_size = list.size();
    first = new unsigned int[list.size()];
    for(std::size_t i = 0; i < list.size(); i++) {
        //Use pointer arithmetic to dereference the elements in list
        first[i] = *(list.begin() + i);
    }
}

UIntVector::UIntVector(const UIntVector & obj) {
    first = new unsigned int[obj.size()];
    vector_size = obj.size();
    for(std::size_t i = 0; i < obj.size(); i++) {
        first[i] = obj[i];
    }
}

UIntVector::UIntVector(UIntVector && obj) {
    vector_size = obj.vector_size;
    first = obj.first;

    obj.first = nullptr;
    obj.vector_size = 0;

}

UIntVector& UIntVector::operator=(UIntVector && other) {
//    vector_size = std::move(other.vector_size);
//    first = std::move(other.first);
    if(this != &other)
    {
        delete [] first;
        first = other.first;
        vector_size = other.vector_size;

        other.first = nullptr;
        other.vector_size = 0;
    }
    return *this;
}

unsigned int& UIntVector::operator[](const std::size_t index) 
{
    if(index < vector_size)
        return first[index];
    throw std::out_of_range("Index out of range");
}

const unsigned int& UIntVector::operator[](const std::size_t index) const
{
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
    delete [] first;
}

void UIntVector::reset()
{
    for(std::size_t i = 0; i < vector_size; i++) {
        first[i] = 0;
    }
}

std::size_t UIntVector::size() const
{
    return vector_size;
}

