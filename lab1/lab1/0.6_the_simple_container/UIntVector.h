#ifndef UINTVECTOR
#define UINTVECTOR


class UIntVector {

    private:
        size_t vector_size;
        unsigned int * first;
    public:
        UIntVector();
        UIntVector(size_t);
        UIntVector(std::initializer_list<unsigned int>);
        UIntVector(const UIntVector & obj);
        UIntVector& operator =(const UIntVector&);
        ~UIntVector();
        unsigned int& operator[] (int);
        const unsigned int& operator[] (int) const;
        void reset();
        std::size_t size() const;
};

#endif
