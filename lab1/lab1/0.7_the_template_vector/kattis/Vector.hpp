#ifndef TVECTOR 
#define TVECTOR 

template <class T> class Vector {
    private:
        std::size_t vector_size, vector_capacity;
        T* vect;
    public:
        Vector();
        Vector(const std::size_t);
        Vector(const std::size_t, const T);
        Vector(const Vector &);
        Vector(Vector&&);
        Vector(const std::initializer_list<T>);


        ~Vector();

        Vector<T>& operator=(const Vector<T>&);
        Vector<T>& operator=(Vector<T>&&);

        T& operator[] (const std::size_t);
        const T& operator[] (const std::size_t) const;


        void push_back(T);
        void insert(std::size_t, T);
        void clear(); // reset
        void erase(std::size_t);

        std::size_t size() const;
        std::size_t capacity() const;

        void checkIfConstructibleAssignable();
        void increaseVectorCapacity();

        /*
        iterator begin();
        iterator end();
        iterator find(T const&);
        */
};

#endif
