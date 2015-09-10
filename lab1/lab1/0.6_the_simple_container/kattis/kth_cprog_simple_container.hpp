#ifndef UINTVECTOR
#define UINTVECTOR


class UIntVector {

    private:
        std::size_t vector_size;
        unsigned int * first;
    public:
        UIntVector();
        UIntVector(const std::size_t);
        UIntVector(const UIntVector &);
        UIntVector(UIntVector&&);
        UIntVector(const std::initializer_list<unsigned int>);

        ~UIntVector();

        UIntVector& operator=(const UIntVector&);
        UIntVector& operator=(UIntVector&&);

        unsigned int& operator[] (const std::size_t);
        const unsigned int& operator[] (const std::size_t) const;
        void reset();
        std::size_t size() const;
};

#endif
