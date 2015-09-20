#include <iostream>
#include <stdexcept>
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
        vect[i] = value;
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
    clear();
}

template <typename T>
Vector<T>& Vector::operator=(const Vector<T>& other)
{
}

template <typename T>
Vector<T>& Vector::operator=(Vector<T>&& other)
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
}


template <typename T>
T& Vector<T>::operator[](const std::size_t index)
{
}

template <typename T>
const T& Vector<T>::operator[](const std::size_t index) const
{
}

template <typename T>
void Vector<T>::push_back(T obj)
{
}

template <typename T>
void Vector<T>::insert(std::size_t index, T obj)
{
}

template <typename T>
void Vector<T>::clear()
{
    for(std::size_t i = 0; i < vector_capacity; i++)
        vect[i] = 0;
}

template <typename T>
void Vector<T>::erase(std::size_t index)
{
}

template <typename T>
std::size_t Vector<T>::size()
{
    return vector_size;
}

template <typename T>
std::size_t Vector<T>::capacity()
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
void Vector<t>::increaseVectorSize()
{
}

/*

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
 */

int main(){
     Vector<double> v;           // ok: defaultkonstruktor ger vektor med flyttal
    Vector<char> *a = new Vector<char>[3];  // dynamiskt allokerade ser ut så här
    delete [] a;
/*
    assert(v.size() == 0);      // tom från början
    v.push_back(3.14);          // lägg till ett element sist 
    assert(v.size() == 1);      // nu ligger ett element i vektorn
    v.insert(0, 2.10);          // lägg till före element 0, dvs först
    assert(v[0] == 2.10 &&      // hamnade de rätt?
	   v[1] == 3.14);       
    assert(v.size() == 2);      // nu ligger två element i vektorn
    v.sort(false);              // sortera i fallande ordning
    assert(v[0] == 3.14 &&      // hamnade de rätt?
	   v[1] == 2.10);       
    assert(v.size() == 2);      // ingenting ändrat?
    v[1] = 2.11;                // tilldelning av enstaka element;

    const Vector<double> &vc = v;  // skapa konstant referens
    assert(vc.size() == 2);     // ok: ändrar ej vektorn som är konstant
    assert(vc[0] == 3.14 &&     // ok: ändrar ej vektorn som är konstant
	   vc[1] == 2.11);
    
    v.erase(0);                 // ta bort första elementet               
    assert(v.size() == 1);      // rätt antal elelment
    v.clear();                  // töm hela vektorn
    assert(v.size() == 0);      // tom när alla element är borttagna
    
    
    // kontrollera att följande rader inte går att kompilera
    vc[0] = 3.1415;             // fel: tilldelning av konstant objekt
    Vector<char> c = v;         // fel: tilldelning av olika typer
*/
    return 0;
}
