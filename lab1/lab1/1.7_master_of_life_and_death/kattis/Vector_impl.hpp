template <class T>
Vector<T>::Vector()
{
    checkIfConstructibleAssignable();
    vector_size = 0;
    vector_capacity = 1;
    vect = allocator.allocate(vector_capacity);
}

template <class T>
Vector<T>::Vector(const std::size_t size)
{
    checkIfConstructibleAssignable();
    vector_size = size;
    vector_capacity = 2*size + 1;
    vect = allocator.allocate(vector_capacity);
    for(size_t i = 0; i < size; i++)
        allocator.construct(&vect[i], T{});
}

template <class T>
Vector<T>::Vector(const std::size_t size, const T value)
{
    checkIfConstructibleAssignable();
    vector_size = size;
    vector_capacity = 2*size + 1;
    vect = allocator.allocate(vector_capacity);
    for(std::size_t i = 0; i < size; i++)
    {
        allocator.construct(&vect[i], value);
    }
}

template <class T>
Vector<T>::Vector(const Vector& v)
{
    checkIfConstructibleAssignable();
    vector_size = v.size();
    vector_capacity = v.capacity();
    vect = allocator.allocate(vector_capacity);
    for(std::size_t i = 0; i < vector_size; i++)
        allocator.construct(&vect[i], v.vect[i]);
}

template <class T>
Vector<T>::Vector(Vector&& v)
{
    vector_size = v.size();
    vector_capacity = v.capacity();
    vect = v.vect;

    v.vect = nullptr;
    v.vector_size = 0;
    v.vector_capacity = 0;
}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> list)
{
    vector_size = list.size();
    vector_capacity = vector_size;
    vect = allocator.allocate(vector_capacity);
    int k = 0;
    for(auto i = list.begin(); i != list.end(); ++i){
        allocator.construct(&vect[k], *i);
//        vect[k] = *i;
        ++k;
    }
    //for(std::size_t i = 0; i < vector_capacity; i++)
     //   vect[i] = list[i];
}

template <class T>
Vector<T>::~Vector()
{
 //   clear();
    for(size_t i = 0; i < vector_size; i++)
        allocator.destroy(&vect[i]);
    allocator.deallocate(vect, vector_capacity);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    Vector<T> tmp(other);
    std::swap(vector_size, tmp.vector_size);
    std::swap(vector_capacity, tmp.vector_capacity);
    std::swap(vect, tmp.vect);
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
    if(this != &other)
    {
        clear();
        allocator.deallocate(vect, vector_capacity);

        vect = other.vect;
        vector_size = other.vector_size;
        vector_capacity = other.vector_capacity;

        other.vect = nullptr;
        other.vector_size = 0;
        other.vector_capacity = 0;
    }
    return *this;
}


template <class T>
T& Vector<T>::operator[](const std::size_t index)
{
    if(index < vector_size && index >= 0)
        return vect[index];
    throw std::out_of_range("Index out of range");
}

template <class T>
const T& Vector<T>::operator[](const std::size_t index) const
{
    if(index < vector_size && index >= 0)
        return vect[index];
    throw std::out_of_range("Index out of range");
}

template <class T>
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

template <class T>
void Vector<T>::push_back(T obj)
{
    if(vector_size == vector_capacity)
        increaseVectorCapacity();
    allocator.construct(&vect[vector_size], obj);
    vector_size += 1;
}

template <class T>
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

    allocator.construct(&vect[index], obj);
    vector_size += 1;

}

template <class T>
void Vector<T>::clear()
{
    for(size_t i = 0; i < vector_size; i++)
        allocator.destroy(&vect[i]);
    vector_size = 0;
}

template <class T>
void Vector<T>::reset()
{
    for(std::size_t i = 0; i < vector_capacity; i++)
        vect[i] = T();
}

template <class T>
void Vector<T>::erase(std::size_t index)
{
    if(index > vector_size - 1 || index < 0 || vector_size == 0)
        throw std::out_of_range("Index out of range");

    for(std::size_t i = index; i < vector_size - 1; i++)
    {
        vect[i] = vect[i+1];
    }
    allocator.destroy(&vect[vector_size - 1]);
    vector_size -= 1;
}

template <class T>
std::size_t Vector<T>::size() const
{
    return vector_size;
}

template <class T>
std::size_t Vector<T>::capacity() const
{
    return vector_capacity;
}

template <class T>
void Vector<T>::checkIfConstructibleAssignable()
{
    static_assert(std::is_move_constructible<T>::value, "Type not eligble");
    static_assert(std::is_move_assignable<T>::value, "Type not eligble");
}

template <class T>
void Vector<T>::increaseVectorCapacity()
{
    int newCapacity = vector_capacity * 2;
    T* tmp_vect = allocator.allocate(newCapacity);
    for(std::size_t i = 0; i < vector_size; i++)
    {
        tmp_vect[i] = vect[i];
    }
    allocator.deallocate(vect, vector_capacity);
    vect = tmp_vect;
    vector_capacity = newCapacity;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return vect;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() 
{
    return vect + vector_size; // from literature
}

template <class T>
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

template <class T>
typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return vect;
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::end() const
{
    return vect + vector_size; // from literature
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::find(T const& val) const
{
    for(auto iterator = begin(); iterator != end(); iterator++)
    {
        if(val == *iterator)
                return iterator;
    }
    return end();
}

