#include "Vector.hpp"

template <typename T>
Vector<T>::Vector()
{
    checkIfConstructibleAssignable();
    vector_size = 0;
    vector_capacity = 0;
    vect = new T[vector_capacity];
}

template <typename T>
Vector<T>::Vector(const std::size_t size)
{
    checkIfConstructibleAssignable();
    vector_size = 0;
    vector_capacity = size;
    vect = new T[vector_capacity];
    clear();
}

template <typename T>
Vector<T>::Vector(const std::size_t size, const T value)
{
    checkIfConstructibleAssignable();
    vector_size = size;
    vector_capacity = size;
    vect = new T[vector_capacity];
    for(std::size_t i = 0; i < size; i++)
    {
        vect[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& v)
{
    checkIfConstructibleAssignable();
    vector_size = v.size();
    vector_capacity = v.capacity();
    vect = new T[vector_capacity];
    for(std::size_t i = 0; i < vector_capacity; i++)
        vect[i] = v[i];
}

template <typename T>
Vector<T>::Vector(Vector&& v)
{
    vector_size = v.size();
    vector_capacity = v.capacity();
    vect = v.vect;

    v.vect = nullptr;
    v.vector_size = 0;
    v.vector_capacity = 0;
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> list)
{
    vector_size = list.size();
    vector_capacity = vector_size;
    vect = new T[vector_capacity];
    for(std::size_t i = 0; i < vector_capacity; i++)
        vect[i] = list[i];
}

template <typename T>
Vector<T>::~Vector()
{
    delete []vect;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    Vector<T> tmp(other);
    std::swap(vector_size, tmp.vector_size);
    std::swap(vector_capacity, tmp.vector_capacity);
    std::swap(vect, tmp.vect);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
    if(this != &other)
    {
        delete []vect;
        vect = other.vect;
        vector_size = other.vector_size;
        vector_capacity = other.vector_capacity;

        other.vect = nullptr;
        other.vector_size = 0;
        other.vector_capacity = 0;
    }
    return *this;
}


template <typename T>
T& Vector<T>::operator[](const std::size_t index)
{
    if(index < vector_size && index >= 0)
        return vect[index];
    throw std::out_of_range("Index out of range");
}

template <typename T>
const T& Vector<T>::operator[](const std::size_t index) const
{
    if(index < vector_size && index >= 0)
        return vect[index];
    throw std::out_of_range("Index out of range");
}

template <typename T>
std::string Vector<T>::print()
{
    std::string a = "[";
    for(std::size_t i = 0; i < vector_size; i++){
        a+=vect[i];
        if(i+1 < vector_size)
            a+=", ";
    }

    a+="]\0";

    return a;
}

template <typename T>
void Vector<T>::push_back(T obj)
{
    if(vector_size == vector_capacity)
        increaseVectorCapacity();
    vect[vector_size] = obj;
    vector_size += 1;
}

template <typename T>
void Vector<T>::insert(std::size_t index, T obj)
{
    if(index > vector_size || index < 0)
        throw std::out_of_range("Index out of range");

    if(vector_size == vector_capacity)
        increaseVectorCapacity();

    if(index == vector_size)
    {
        push_back(obj);
        return;
    }

    for(std::size_t i = vector_size; i > index; i--)
    {
        vect[i] = vect[i-1];
    }
    vect[index] = obj;
    vector_size += 1;

}

template <typename T>
void Vector<T>::clear()
{
    vector_size = 0;
    delete [] vect;
    vect = new T[vector_capacity];
}

template <typename T>
void Vector<T>::reset()
{
    for(std::size_t i = 0; i < vector_capacity; i++)
        vect[i] = T();
}

template <typename T>
void Vector<T>::erase(std::size_t index)
{
    for(std::size_t i = index; i < vector_size; i++)
    {
        vect[i] = vect[i+1];
    }
    vect[vector_size - 1] = 0;
    vector_size -= 1;
}

template <typename T>
std::size_t Vector<T>::size() const
{
    return vector_size;
}

template <typename T>
std::size_t Vector<T>::capacity() const
{
    return vector_capacity;
}

template <typename T>
void Vector<T>::checkIfConstructibleAssignable()
{
    static_assert(std::is_move_constructible<T>::value, "Type not eligble");
    static_assert(std::is_move_assignable<T>::value, "Type not eligble");
}

template <typename T>
void Vector<T>::increaseVectorCapacity()
{
    int newCapacity = vector_capacity * 2;
    T* tmp_vect = new T[newCapacity];
    for(std::size_t i = 0; i < vector_size; i++)
    {
        tmp_vect[i] = vect[i];
    }
    delete []vect;
    std::swap(vect, tmp_vect);
    vector_capacity = newCapacity;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return vect;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() 
{
    return vect + vector_size; // from literature
}

template <typename T>
typename Vector<T>::iterator Vector<T>::find(T const& val)
{
    for(auto iterator = begin(); iterator != end(); iterator++)
    {
            if(val == *iterator){
                return iterator;
            }
    }

    return end();
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return vect;
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
    return vect + vector_size; // from literature
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::find(T const& val) const
{
    for(auto iterator = begin(); iterator != end(); iterator++)
    {
        if(val == *iterator)
                return iterator;
    }
    return end();
}

